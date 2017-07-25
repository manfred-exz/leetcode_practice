/* see https://1drv.ms/u/s!Avvs2L2STwYvyFir-HWZ99m9j_Cc for note */
#[macro_use]
extern crate text_io;

use std::f64;

fn get_non_2_5_factor(num: u32) -> Vec<u32> {
    let mut res: Vec<u32> = Vec::new();
    let mut num = num;
    while num % 2 == 0 {
        num /= 2;
    }
    while num % 5 == 0 {
        num /= 5;
    }
    let max_factor = (num as f32).sqrt().ceil() as u32;
    for factor in 2..max_factor + 1 {
        if num == 1 {
            break;
        }
        while num % factor == 0 {
            res.push(factor);
            num /= factor;
        }
    }

    if num != 1 {
        res.push(num)
    }

    res
}

fn is_k_for_max_p_terminating(n: u32) -> bool {
    // for why this is the k for max(P), check the onenote link at top
    let k_for_max_p: f64 = n as f64 / f64::consts::E;
    let mut k_for_max_p: u32 = k_for_max_p.round() as u32;

    while k_for_max_p % 2 == 0 {
        k_for_max_p /= 2;
    }

    while k_for_max_p % 5 == 0 {
        k_for_max_p /= 5;
    }

    let non_2_5_factor_of_n = get_non_2_5_factor(n);
    for factor in non_2_5_factor_of_n {
        if k_for_max_p % factor == 0 {
            k_for_max_p /= factor;
        }
    }

    // return if max(P) is terminating decimal
    k_for_max_p == 1
}

fn d(n: u32) -> i32 {
    if is_k_for_max_p_terminating(n) {
        return 0 - (n as i32);
    } else {
        return n as i32;
    }
}

fn sum_d(n: u32) -> i64 {
    let mut sum: i64 = 0;
    for i in 5..(n + 1) {
        let d_i = d(i);
        sum += d_i as i64
    }
    sum
}

fn main() {
    let q: u32 = read!();
    for _ in 0..q {
        let n: u32 = read!();
        println!("{}", sum_d(n));
    }
}
