use std::io;

const MOD: i32 = 1e9 as i32 + 7;

fn is_good(n: u32, nums: &[u32; 2]) -> bool {
    for c in n.to_string().chars() {
        if !nums.contains(&c.to_digit(10).unwrap()) {
            return false;
        }
    }
    true
}

fn exp(a: u32, b: u32) {
    0
}

fn inv(a: u32) {}

fn choose(n: u32, k: u32) {}

fn main() {
    let mut nums = String::new();
    io::stdin().read_line(&mut nums).unwrap();
    let nums: Vec<u32> = nums
        .split_whitespace()
        .map(|x| x.parse::<u32>().unwrap())
        .collect();
    let (a, b, n) = (nums[0], nums[1], nums[2]);

    for i in 1..=(a.max(b) * n) {
        if is_good(i, &[a, b]) {
            for j in 0..=n {
                if j * a + (n - j) * b == i {
                    println!("Van valamennyi: {j} {n}");
                }
            }
        }
    }
}
