use std::io;

const MOD: i32 = 1e9 as i32 + 7;

fn main() {
    let mut nums = String::new();
    io::stdin().read_line(&mut nums).unwrap();
    let nums: Vec<i32> = nums
        .split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect();

    let (a, b, n) = (nums[0], nums[1], nums[2]);

    let good_nums: Vec<i32> = (1..=(a.max(b) * n))
        .filter(|&x| {
            for c in x.to_string().chars() {
                if ![a, b].contains(&(c as i32 - '0' as i32)) {
                    return false;
                }
            }
            true
        })
        .collect();
    let m = good_nums.len();
}
