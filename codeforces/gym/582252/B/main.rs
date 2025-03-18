use std::convert::TryInto;
use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let (a, b, c): (i32, i32, i32) = line
        .split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect::<Vec<_>>()
        .try_into()
        .unwrap();
}
