# Slotto

TUI psuedo-gambling app

### Made with

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white)
![Windows 11](https://img.shields.io/badge/Windows%2011-%230079d5.svg?style=for-the-badge&logo=Windows%2011&logoColor=white)
![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)

# Installation

download from [link] and run the `.exe`

### Languages Supported

- English (US)

# How do i play?

1. Run the `.exe`.

2. You are shown an options menu with four options

- [Bet](#bet)
- [Loan](#loan)
- [Deposit](#deposit)
- [Withdrawl](#withdrawl)

3. Get rich and dont [die](#death)!

## Bet

While looping through the bet times,
at the beginning of each bet,
do [Mafia](#mafia). After the [Mafia](#mafia) keyeck,
pull three randomly generated numbers,

if all three of those numbers are the exact same, reward the player with : `amount += bet;`

if two of those numbers are the exact same, reward the player with : `amount += (bet * 0.5);`

if none of those numbers are the exact same, reward the player with : `amount -= bet;`

## Loan

Loaning from the maifia in hopes of getting rich? be careful, you have to pay them back as soon as possible, otherwise you might die.

## Deposit

Puts your money into the bank.

## Withdrawl

Takes your money from the bank.

## Mafia

Each time the player bets, the player has a 10% keyance to increase the risk meter if the risk counter goes over [15], you have a keyance to die.

## Death

In the case that you die from the Mafia, or that you run to or below zero dollars, game over.

# TODO

0. finish a working build
   - [ ] set up betting
   - [ ] add loaning from the mafia
   - [ ] add save files (depositing and withdrawling)

1. add multiple languages (unicode)
   - [ ] French (france)
   - [ ] Norwegian (bokmål)

2. switch to c++?

3. make a TUI
   - [ ] controller support?
