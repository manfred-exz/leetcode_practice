#[macro_use] extern crate text_io;

fn main() {
    let q: usize = read!();

    for _ in 0..q {
        let n: usize = read!();
        let length = 2*n as usize;
        let index = |row: usize, col: usize| -> usize { row * length + col };

        let mut matrix: Vec<u32> = Vec::new();
        matrix.resize(length * length, 0);
        for row in 0..length {
            for col in 0..length {
                matrix[index(row, col)] = read!();
            }
        }

        let mut sum: u32 = 0;
        for row in 0..n {
            for col in 0..n {
                let top_left = matrix[index(row, col)];
                let top_right = matrix[index(row, length - 1 - col)];
                let bottom_left = matrix[index(length - 1 - row, col)];
                let bottom_right = matrix[index(length - 1 - row, length - 1 - col)];

                let nums = vec![top_left, top_right, bottom_left, bottom_right];
                let max = nums.iter().max_by(|x, y| x.cmp(y)).unwrap();
                sum += *max;
            }
        }

        println!("{}", sum);
    }
}
