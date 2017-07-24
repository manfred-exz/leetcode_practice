use std::io;
fn read_numbers() -> Vec<u32> {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("cannot read from input");

    input.split_whitespace()
        .map(|x| x.parse::<u32>().expect("parse error: not a number"))
        .collect::<Vec<u32>>()
}

fn main() {
    let mut score_a = 0;
    let mut score_b = 0;
    let a = read_numbers();
    let b = read_numbers();
    for i in 0..3 {
        if a[i] > b[i]{ score_a += 1; }
        if a[i] < b[i]{ score_b += 1; }
    }
    println!("{} {}", score_a, score_b);
}
