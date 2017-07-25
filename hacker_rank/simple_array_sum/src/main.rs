use std::io;

fn read_one_number() -> u32 {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("cannot read from input");

    input.trim().parse::<u32>().expect("not a number")
}

fn read_numbers() -> Vec<u32> {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("cannot read from input");

    input.split_whitespace()
        .map(|x| x.parse::<u32>().expect("parse error: not a number"))
        .collect::<Vec<u32>>()
}

fn main() {
    let count : u32 = read_one_number();
    if count == 0 {
        println!("{}", 0);
        return
    }
    let nums = read_numbers();
    let mut sum: u32 = 0;
    for num in nums{
        sum += num;
    }
    println!("{}", sum);
}
