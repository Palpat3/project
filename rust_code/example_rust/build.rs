fn main() {
    println!("cargo:rustc-link-search=../../c_code");
    println!("cargo:rustc-link-lib=static=vulnerable");
}