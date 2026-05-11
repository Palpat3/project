fn main() {
    let max: i32 = i32::MAX;

    println!("Max i32 value: {}", max);
    println!("Max i32 value + 1: {}", max + 1); // This will cause an integer overflow and wrap around to a negative value
}

