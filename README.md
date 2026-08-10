# ⚽ Football (and Soccer) - Tournament Standings Tracker

A robust C++ solution for processing tournament match results and generating sorted standings tables based on multiple ranking criteria.

## 📖 About the Problem
The program simulates sports tournament management. It takes tournament names, participating teams, and a list of played match results, then computes and outputs the current standings sorted strictly according to the following official rules:

1. **Most points earned** (Win = 3 pts, Tie = 1 pt, Loss = 0 pts).
2. **Most wins**.
3. **Most goal difference** (Goals Scored - Goals Against).
4. **Most goals scored**.
5. **Fewest games played**.
6. **Lexicographical order** (Case-insensitive).

---

## 📂 Input & Output Format

* **Input Format:** Processes $N$ tournaments. Each tournament includes team names, the number of played games, and match scores formatted as:
  `Team_A#goals1@goals2#Team_B`
* **Output Format:** Generates ranked standings showing points, games played, wins-ties-losses breakdown, goal difference, and goals scored/against.

---

## 🚀 Technologies Used
* **Language:** C++
* **Concepts:** Custom Sorting, Structures / Objects, String Parsing, Algorithms.

---

## 💡 How to Run

1. Clone the repository:
   ```bash
   git clone [https://github.com/YOUR_USERNAME/REPOSITORY_NAME.git](https://github.com/YOUR_USERNAME/REPOSITORY_NAME.git)
   g++ main.cpp -o solution
   ./solution

## 📂 Sample Input & Output

```text
2
World Cup 1998 - Group A
4
Brazil
Norway
Morocco
Scotland
6
Brazil#2@1#Scotland
Norway#2@2#Morocco
Scotland#1@1#Norway
Brazil#3@0#Morocco
Morocco#3@0#Scotland
Brazil#1@2#Norway
Some strange tournament
5
Team A
Team B
Team C
Team D
Team E
5
Team A#1@1#Team B
Team A#2@2#Team C
Team A#0@0#Team D
Team E#2@1#Team C
Team E#1@2#Team D

## 📂 Sample Output

World Cup 1998 - Group A
1) Brazil 6p, 3g (2-0-1), 3gd (6-3)
2) Norway 5p, 3g (1-2-0), 1gd (5-4)
3) Morocco 4p, 3g (1-1-1), 0gd (5-5)
4) Scotland 1p, 3g (0-1-2), -4gd (2-6)
Some strange tournament
1) Team D 4p, 2g (1-1-0), 1gd (2-1)
2) Team E 3p, 2g (1-0-1), 0gd (3-3)
3) Team A 3p, 3g (0-3-0), 0gd (3-3)
4) Team B 1p, 1g (0-1-0), 0gd (1-1)
5) Team C 1p, 2g (0-1-1), -1gd (3-4)
