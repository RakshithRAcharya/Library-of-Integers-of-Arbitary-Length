# Library-of-Integers-of-Arbitary-Length

Library "intal" - Integer of arbitray length
intal is a nonnegative integer of arbitrary length (not more than 1000 decimal digits).
The integer is stored as a null terminated string of ASCII characters.
String of decimal digits ('0' thru '9') are stored in big endian style.
That is, the most significant digit is at the head of the string.
Eg: Integer 25 is stored in str as '2' at str[0], '5' at str[1], and null char at str[2].


//FUNCTIONS//

int convert_to_int(char ch);
//Converts the given character into an integer

char convert_to_char(int in);
//Converts the given integer into Character

char* intal_add(const char* intal1, const char* intal2);
// Returns the sum of two intals(INTeger-of-Arbitary-Length).

int intal_compare(const char* intal1, const char* intal2);
// Returns the comparison value of two intals.
// Returns 0 when both are equal.
// Returns +1 when intal1 is greater, and -1 when intal2 is greater.

char* intal_diff(const char* intal1, const char* intal2);
// Returns the difference (obviously, nonnegative) of two intals.

char* intal_multiply(const char* intal1, const char* intal2);
// Returns the product of two intals.

char* intal_mod(const char* intal1, const char* intal2);
// Returns intal1 mod intal2
// The mod value should be in the range [0, intal2 - 1].
// intal2 > 1
// Implement a O(log intal1) time taking algorithm.
// O(intal1 / intal2) time taking algorithm may exceed time limit.
// O(intal1 / intal2) algorithm may repeatedly subtract intal2 from intal1.
// That will take intal1/intal2 iterations.
// You need to design a O(log intal1) time taking algorithm.

char* intal_pow(const char* intal1, unsigned int n);
// Returns intal1 ^ intal2.
// Let 0 ^ n = 0, where n is an intal.
// Implement a O(log n) intal multiplications algorithm.
// 2^3000 has less than 1000 decimal digits. 3000 intal multiplications may exceed time limit.

char* intal_gcd(const char* intal1, const char* intal2);
/ Returns Greatest Common Devisor of intal1 and intal2 using Euclid Theorem.
// Let GCD be "0" if both intal1 and intal2 are "0" even though it is undefined, mathematically.

char* intal_fibonacci(unsigned int n);
// Returns nth fibonacci number.
// intal_fibonacci(0) = intal "0".
// intal_fibonacci(1) = intal "1".

char* intal_factorial(unsigned int n);
// Returns the factorial of n.

char* intal_bincoeff(unsigned int n, unsigned int k);
// Returns the Binomial Coefficient C(n,k) using Dynamic programming.
// 0 <= k <= n
// C(n,k) < 10^1000 because the returning value is expected to be less than 10^1000.
// Use the Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1)
// Make sure the intermediate intal values do not cross C(n.k).

int intal_max(char **arr, int n);**
// Returns the offset of the largest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000

int intal_min(char **arr, int n);**
// Returns the offset of the smallest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000

int intal_search(char **arr, int n, const char* key);**
// Returns the offset of the first occurrence of the key intal in the array.
// Returns -1 if the key is not found.
// 1 <= n <= 1000

int intal_binsearch(char **arr, int n, const char* key);**
// Returns the offset of the first occurrence of the key intal in the SORTED array.
// Returns -1 if the key is not found.
// The array is sorted in nondecreasing order.
// 1 <= n <= 1000
// The implementation done in an O(log n) algorithm.

void intal_sort(char **arr, int n);**
// Sorts the array of n intals.
// 1 <= n <= 1000
// The implementationdone in an O(n log n) algorithm.

char* coin_row_problem(char **arr, int n);**
// Coin-Row Problem - Dynamic Programming Solution
// There is a row of n coins whose values are some positive integers C[0..n-1].
// The goal is to pick up the maximum amount of money subject to the constraint that
// no two coins adjacent in the initial row can be picked up.
// 1 <= n <= 1000
// The implementation should be O(n) time and O(1) extra space.
// Eg: Coins = [10, 2, 4, 6, 3, 9, 5] returns 25

THAT'S ALL FOLKS!!
