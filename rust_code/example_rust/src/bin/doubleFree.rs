fn main() {
    let p = Box::new(42);
    println!("Value before free: {}", p);
    drop(p); // Explicitly drop the value, simulating a free
    println!("dropped once");
    drop(p); // This will cause a compile-time error due to double free
    println!("Dropped twice");
}