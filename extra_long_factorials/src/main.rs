extern crate num;
use std::io;
use std::ops::Mul;
use num::*;
use num::FromPrimitive;
use num::bigint::BigUint;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("cannot read");
    let n: u32 = input.trim().parse::<u32>().expect("not a valid number");
    let mut fact: BigUint = BigUint::one();
    for i in 1..(n+1) {
        fact = fact.mul(BigUint::from_u32(i).expect("why..."));
    }
    println!("{}", fact);
}
