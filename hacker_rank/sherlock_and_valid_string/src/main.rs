use std::io;
use std::collections::HashMap;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("error read");
    let mut freq: HashMap<char, u32> = HashMap::new();

    for c in input.trim().chars(){
        if freq.contains_key(&c) {
            *freq.get_mut(&c).unwrap() += 1;
        } else{
            freq.insert(c, 1);
        }
    }

//    println!("freq = {:?}", freq);

    let mut count_of_same_freq: HashMap<u32, u32> = HashMap::new();
    for v in freq.values(){
        if count_of_same_freq.contains_key(v) {
            *count_of_same_freq.get_mut(v).unwrap() += 1;
        } else {
            count_of_same_freq.insert(*v, 1);
        }
    }

//    println!("count_of_same_freq = {:?}", count_of_same_freq);

    if count_of_same_freq.len() == 1{
        println!("YES");
        return;
    }

    if count_of_same_freq.len() == 2{
        let mut bigger_count: Option<(u32, u32)> = None;
        let mut one_count: Option<(u32, u32)> = None;
        let mut found_one: bool = false;
        for (key, value) in &count_of_same_freq {
            if found_one == true {
                bigger_count = Some((*key, *value));
                continue;
            }
            if *value == 1 {
                one_count = Some((*key, *value));
                found_one = true;
            } else {
                bigger_count = Some((*key, *value));
            }
        }

        if let Some((one_key, _)) = one_count {
            if one_key == 1 || bigger_count.unwrap() == (1, 1){
                println!("YES");
                return;
            }
            if (one_key as i32 - bigger_count.unwrap().0 as i32).abs() == 1{
                println!("YES");
                return;
            }
        }
    }
    println!("NO");
}
