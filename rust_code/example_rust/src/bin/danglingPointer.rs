fn get_local() -> &i32 {
    let x = 42;
    &x // This will cause a compile-time error due to returning a reference to a local variable
}

fn main() {
    let dangling_ref = get_local();
    println!("Dangling reference value: {}", dangling_ref);
}