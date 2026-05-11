fn main() {
    let buffer = [0u8; 8];
    let secret = 420;

    println!("Before buffer overflow: secret = {}", secret);
    println!("Buffer content: {:?}", buffer);
    println!("Value at index 20: {}", buffer[20]); // This will cause a panic due to out-of-bounds access
    println!("After buffer overflow: secret = {}", secret);
}