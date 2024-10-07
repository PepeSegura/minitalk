# :desktop_computer: Minitalk

## :card_file_box: Introduction

The purpose of this project is to code a small data exchange program using UNIX signals. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus. 

## :question: Why I Did This Project

I realized that most of the projects submitted on my campus or those ususaly seen on github did not follow the subject, so I just really wanted to know if the subject was possible with its limitations.

Representation of my approach, where the Server receives the hole string before showing it:
![Pepe](https://github.com/PepeSegura/minitalk/blob/682e66145d425a0cbfe31b74b4594a359a0bb2ea/gifs/pepetalk.gif)

The type of solution that is usually seen:
![BadTalk](https://github.com/PepeSegura/minitalk/blob/682e66145d425a0cbfe31b74b4594a359a0bb2ea/gifs/badtalk.gif)

## :round_pushpin: Mandatory part

Create a communication program in the form of a client and a server.
- The server must be started first. After its launch, it has to print its PID.
- The client takes two parameters:
  - The server PID.
  - The string to send.
- **The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.**
- The server has to display the string pretty quickly. Quickly means that if you think
it takes too long, then it is probably too long.
1 second for displaying 100 characters is way too much!
- Your server should be able to receive strings from several clients in a row without
needing to restart.
- The communication between your client and your server has to be done only using
UNIX signals.
- You can only use these two signals: **SIGUSR1** and **SIGUSR2**.

```
./client $(xclip -out) $(python3 -c 'print("A" * 100000)')
```

## :bangbang: Bonus part

- The server acknowledges every message received by sending back a signal to the
client.
- Unicode characters support!

## Tasks

- :ballot_box_with_check: Mandatory part
- :ballot_box_with_check: Bonus part
