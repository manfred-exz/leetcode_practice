#[macro_use]
extern crate text_io;

fn num_cmp(a: &String, b: &String) -> std::cmp::Ordering {
    use std::cmp::Ordering;
    if a.len() < b.len() {return Ordering::Less;}
    if a.len() > b.len() {return Ordering::Greater;}
    return a.cmp(&b);
}

fn main() {
    let n: u32 = read!();
    let mut str_vec: Vec<String> = Vec::new();
    for _ in 0..n {
        let input: String = read!();
        str_vec.push(input);
    }

    str_vec.sort_by(|a, b| {
        num_cmp(a, b)
    });

    for str in str_vec{
        println!("{}", str);
    }
}
