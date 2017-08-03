#[macro_use]
extern crate text_io;

fn pair_index(a: usize, container: &[u8]) -> usize {
    container.len() - 1 - a
}

fn main() {
    let nine = '9' as u8;

    let n: u32 = read!();
    let k: u32 = read!();
    let mut input_digits = String::new();
    std::io::stdin().read_line(&mut input_digits).unwrap();
    input_digits = String::from(input_digits.trim());
    let digits: Vec<u8> = input_digits.into_bytes();
//    println!("digits read: {}", String::from_utf8(digits.clone()).unwrap());

    let mut changes_to_use = k;
    let num_of_pairs = digits.len() / 2;

    let mut changes_needed = 0u32;
    for i in 0..num_of_pairs {
//        println!("digits[{}] = {}, digits[{}] = {}", i, digits[i], pair_index(i, &digits), digits[pair_index(i, &digits)]);
        if digits[i] != digits[pair_index(i, &digits)] {
            changes_needed += 1
        }
    }

//    println!("changes_to_use = {}, changes_needed = {}", changes_to_use, changes_needed);

    let mut result_digits: Vec<u8> = Vec::new();
    result_digits.resize(digits.len(), 0);
    for i in 0..num_of_pairs {
        let pair_i = pair_index(i, &digits);
        if changes_to_use < changes_needed {
            println!("-1");
            return;
        }
        let curr_free_changes_to_use = changes_to_use - changes_needed;
        let a = digits[i];
        let b = digits[pair_i];

        if a == b {
            if a != nine && curr_free_changes_to_use >= 2 {
                result_digits[i] = nine;
                result_digits[pair_i] = nine;
                changes_to_use -= 2;
                changes_needed -= 0;
            } else {
                result_digits[i] = digits[i];
                result_digits[pair_i] = digits[pair_i];
            }
        } else {
            if a != nine && b != nine && curr_free_changes_to_use >= 1 {
                result_digits[i] = nine;
                result_digits[pair_i] = nine;
                changes_to_use -= 2;
                changes_needed -= 1;
            } else {
                let max_digit = std::cmp::max(a, b);
                result_digits[i] = max_digit;
                result_digits[pair_i] = max_digit;
                changes_to_use -= 1;
                changes_needed -= 1;
            }
        }
    }

    if num_of_pairs * 2 < digits.len() {
        result_digits[num_of_pairs] = if changes_to_use >= 1 { nine } else { digits[num_of_pairs] };
    }

    println!("{}", String::from_utf8(result_digits).unwrap());
}
