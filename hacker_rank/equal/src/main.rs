use std::io;
use std::u32;
#[macro_use]
extern crate text_io;
fn main() {
    let t: u32 = read!();
    for _ in 0..t {
        let n: u32 = read!();
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let numbers: Vec<u32> = input.trim().split(' ').map(|x| x.parse::<u32>().unwrap()).collect();
        println!("{}", solve(&numbers));
    }
}

fn solve(numbers: &[u32]) -> u32 {
    let min_num = numbers.iter().fold(u32::MAX, |curr_min, &x| std::cmp::min(curr_min, x));
    let mut min_num_of_steps = u32::MAX;
    for i in 0..5 {
        let numbers: Vec<u32> = numbers.iter().map(|x| x - min_num + i).collect();
        let num_of_steps: u32 = numbers.iter().fold(0, |curr_sum, &x| curr_sum + required_steps(x));
        min_num_of_steps = std::cmp::min(min_num_of_steps, num_of_steps);
    }
    min_num_of_steps
}

fn required_steps(num: u32) -> u32 {
    let mut num = num;
    let mut count = 0;
    count += num / 5;
    num = num % 5;

    count += num / 2;
    num = num % 2;

    count += num;
    count
}