#[macro_use] extern crate text_io;

fn main() {
    let count: u32 = read!();
    for _ in 0..count {
        let score: u32 = read!();
        if (score >= 38) && (score % 5 >= 3) {
            println!("{}", score + 5 - (score % 5));
        } else{
            println!("{}", score);
        }
    }
}
