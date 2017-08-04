#[macro_use] extern crate text_io;
fn main() {
    let n: u32 = read!();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut calories: Vec<u32> = input.split_whitespace()
        .map(|x| x.parse::<u32>().unwrap()).collect();
    calories.sort();
    calories.reverse();
    let mut total_calories = 0u64;
    for (idx, calorie) in calories.iter().enumerate() {
        total_calories += *calorie as u64 * 2u64.pow(idx as u32);
    }
    println!("{}", total_calories);
}
