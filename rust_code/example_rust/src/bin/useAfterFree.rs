fn main() {
    let p = Box::new(42);

    println!("Value before free: {}", p);

    drop(p); // Explicitly drop the value, simulating a free

    println!("Value after free: {}", p); // This will cause a compile-time error due to use after free
}