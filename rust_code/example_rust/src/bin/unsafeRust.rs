use std::alloc::{alloc, dealloc, Layout};

fn use_after_free() {
    unsafe {
        let layout = Layout::new::<i32>(); // Define the layout for the memory allocation

        let p = alloc(layout) as *mut i32; // Allocate memory without initialization

        *p = 42; // Write to the allocated memory

        println!("Value at pointer first: {}", *p); // Read from the allocated memory

        dealloc(p as *mut u8, layout);      // like free()

        println!("Value at pointer: {}", *p); // Read from the allocated memory
    }
}

unsafe extern "C" {
    fn vulnerable_c_function(buf: *mut u8, input: *const u8);
}

fn main() {
    use_after_free();

    let mut buffer = [0u8; 8];
    let adjacent: u64 = 0xDEADBEEF;  // sits next to buffer in memory

    let long_input = b"This is a long string that will overflow the buffer\0";

    println!("Buffer size: {} bytes", buffer.len());
    println!("Input size: {} bytes", long_input.len());
    println!("Adjacent value before: {:#X}", adjacent);

    println!("Calling vulnerable C function...");
    println!("Buffer before: {:?}", buffer);

    unsafe {
        vulnerable_c_function(buffer.as_mut_ptr(), long_input.as_ptr());
    }

    println!("Buffer after: {:?}", buffer);
    println!("Adjacent value after: {:#X}", adjacent);  // should be corrupted

    println!("Done, if this line is reached, overflow happened silently")
}

//uses c library to show how rust can use ensafe external code and how it can cause memory safety issues if not used carefully.