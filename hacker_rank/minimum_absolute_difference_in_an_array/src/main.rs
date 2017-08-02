#[macro_use]
extern crate text_io;

fn main() {
    let n: u32 = read!();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut nums: Vec<i32> = input.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();

    nums.sort();

    let mut min_diff = (nums[1] - nums[0]).abs();
    for i in 1..nums.len()-1 {
        let diff = (nums[i] - nums[i+1]).abs();
        min_diff = std::cmp::min(min_diff, diff);
    }

    println!("{}", min_diff);
}
