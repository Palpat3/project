struct Student {
    name: String, //growable
    id: u32, //fixed size
    grade: f32, //fixed size
}

impl Student {
    fn new(name: &str, id: u32, grade: f32) -> Student {
        Student { 
            name: name.to_string(), // convert to String type
            id,
            grade 
        }
    }
    fn print_info(&self) {
        println!("Student: {} | ID: {} | Grade: {:.1}", self.name, self.id, self.grade);
    }

}

fn main() {
    println!("=== Student Information System ===");

    println!("-- Adding students --");
    let s1 = Student::new("Alice", 1, 4.5);
    let s2 = Student::new("Bob", 2, 3.8);
    s1.print_info();
    s2.print_info();

    println!("-- Long name student --");
    let s3 = Student::new("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 3, 2.5);
    s3.print_info();

    println!("-- integer overflow test --");
    let id: u32 = u32::MAX; // Maximum value for u32
    let s4 = Student::new("Charlie", id, 3.0);
    s4.print_info();
    //Overflow

    //let s5 = Student::new("Dave", id + 1, 3.2); // This will cause an integer overflow for the id
    //s5.print_info();

    println!("-- delete student --");
    //drop(s1); // Explicitly drop student1, simulating a delete
    // s1.print_info(); // This will cause a compile-time error due to use after free

    //println!("-- dangling pointer test --");
    let _dangling_ref = &s1; // This is a reference to s1, which has been dropped
    //println!("Dangling reference value: {}", dangling_ref.name); // This will cause a compile

    //drop(s1); // Explicitly drop student1 again, simulating a double free
    



}

