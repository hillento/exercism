pub fn eggCount(number: usize) usize {
    var num: usize = number;
    var sum: usize = 0;
    while (num > 0) {
        if (num % 2 != 0) sum = sum + 1;
        num = num / 2;
    }
    return sum;
}
