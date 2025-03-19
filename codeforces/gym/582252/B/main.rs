use std::io;

const MOD: i32 = 1e9 as i32 + 7;

fn is_good(n: u32) {
    for c in n.to_string().chars() {
        if ![a, b].contains(&c.to_digit(10).unwrap()) {
            return false;
        }
    }
    true
}

fn main() {
    let mut nums = String::new();
    io::stdin().read_line(&mut nums).unwrap();
    let nums: Vec<u32> = nums
        .split_whitespace()
        .map(|x| x.parse::<u32>().unwrap())
        .collect();

    let (a, b, n) = (nums[0], nums[1], nums[2]);

    for i in 1..=(a.max(b) * n) {
        if is_good(i) {
            println!("{}", i);
        }
    }
}
