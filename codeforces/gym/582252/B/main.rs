use std::convert::TryInto;
use std::io;

fn main() {
    let mut nums = String::new();
    io::stdin().read_line(&mut nums).unwrap();
    let nums = nums
        .split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect();
}
