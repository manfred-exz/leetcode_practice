use std::io;
fn super_reduce(to_reduce: &mut Vec<u8>) {
    let mut idx = 1;
    while idx < to_reduce.len(){
        if idx >= 1 && to_reduce[idx] == to_reduce[idx-1] {
            to_reduce.remove(idx);
            to_reduce.remove(idx-1);
            idx = idx - 1;  // still checking this position
        } else {
            idx += 1;   // continue to next position;
        }
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("cannot read input");
    let mut input = Vec::from(input.as_bytes());
    super_reduce(&mut input);
    if input[0] == b'\n' {
        println!("Empty String");
    } else {
        println!("{}", String::from_utf8(input).unwrap());
    }
}
