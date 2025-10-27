# UPEcman – UPE Pacman

**Academic project for the Automation course – 2024.2**  
This project is an implementation of the classic Pac-Man game using the `ncurses` library in C/C++. The goal is to study programming logic, basic artificial intelligence, and agent behavior control in an academic environment.

## Ghosts

### Blinky
- **Name in English:** Blinky  
- **English nickname:** Shadow  
- **Name in Japanese:** Oikake  
- **Japanese nickname:** Akabei  
- **Superpower alter-ego name:** Cruise Elroy  
- **Color:** Red  
- **Personality:** pursuer, chaser, aggressive, simple minded, determined, tenacious, cruiser  
- **Characteristics:**  
  - The first ghost to track Pacman down  
  - Very hard to shake off  
  - It targets Pacman directly  
  - **When enhanced Cruise Elroy is summoned:** greater speed by 5%, scatter mode do not scatter anymore  
  - **Ghost house:** starts outside and if inside exits immediately  
- **Scatter mode target:** upper-right corner (as Blinky), and Pacman (as Elroy)  
- **Portuguese:**  
  - Name: Oto or Barnabé  
  - Superpower name: Elvis or Super-Oto  
  - Nickname: Sombra  

### Pinky
- **Name in English:** Pinky  
- **English nickname:** Speedy  
- **Name in Japanese:** Machibuse  
- **Japanese nickname:** Pinky  
- **Color:** Pink  
- **Personality:** ambusher, lurker, ambuscader  
- **Characteristics:**  
  - It likes to cut Pacman off  
  - Works harmoniously with Blinky: it goes from the front while Blinky pursues from behind  
  - It targets 4 tiles straight ahead of Pacman  
  - The most intelligent of the group  
  - **Ghost house:** the first to get out (Blinky is already outside)  
- **Scatter mode target:** upper-left corner  
- **Portuguese:**  
  - Name: Pascoal  
  - Nickname: Traíra  

### Inky
- **Name in English:** Inky  
- **English nickname:** Bashful  
- **Name in Japanese:** Kimagure  
- **Japanese nickname:** Aosuke  
- **Color:** Cyan (light blue)  
- **Personality:** fickle, moody, uneven temper, unpredictable, whimsical, antisocial  
- **Characteristics:**  
  - Changes from:  
    - Aggressive (like Blinky), if near Pacman  
    - Trickery (like Pinky), if in a medium distance of Pacman  
    - Distracted (like Clyde), if far away from Pacman  
  - It can be the most hard ghost to avoid due to its triple personality  
  - Targets a tile in front of Pacman opposite to Blinky's position  
  - **Ghost house:** it is the second to exit, only after Pinky  
- **Scatter mode target:** lower-right corner  
- **Portuguese:**  
  - Name: Igor  
  - Nickname: Doido  

### Clyde
- **Name in English:** Clyde  
- **English nickname:** Pokey  
- **Name in Japanese:** Otoboke  
- **Japanese nickname:** Guzuta  
- **Color:** Orange  
- **Personality:** sluggish, stupid, dopey, feigning ignorance, short-sighted  
- **Characteristics:**  
  - It chases Pacman from distance  
  - If it is near, it will change its target to its preferred corner  
  - **Ghost house:** the last to get out  
- **Scatter mode target:** lower-left corner  
- **Portuguese:**  
  - Name: Clemente  
  - Nickname: Pateta  

## Scatter Mode
- The ghosts will chase Pacman for 20 seconds, then scatter for 7 seconds; and repeat the loop.

## Amazing Pacman
> "Pac-Man is an amazing example of seemingly-complex behavior arising from only a few cleverly-designed rules, with the result being a deep and challenging game that players still strive to master, 30 years after its release." – Chad Birch, 2010

## References
- [Google Doodles – 30th Anniversary of Pac-Man](https://www.google.com/doodles/30th-anniversary-of-pac-man)  
- [Garotas Geeks – 5 things you didn't know about Pac-Man](http://www.garotasgeeks.com/5-coisas-que-voce-nao-sabia-sobre-o-pac-man/)  
- [Destructoid – Blinky, Inky, Pinky, and Clyde](https://www.destructoid.com/blinky-inky-pinky-and-clyde-a-small-onomastic-study-108669.phtml)  
- [Game Internals – Understanding Pac-Man Ghost Behavior](http://gameinternals.com/post/2072558330/understanding-pac-man-ghost-behavior)  
- [Gamasutra – The Pac-Man Dossier](http://www.gamasutra.com/view/feature/3938/the_pacman_dossier.php?print=1)  
- [Don Hodges – Pacman Pinky Explanation](http://donhodges.com/pacman_pinky_explanation.htm)  
- [Today I Found Out – Ghost Strategies](https://www.todayifoundout.com/index.php/2015/10/ghosts-pac-man-work/)  
- [Mental Floss – Learning different strategies for each ghost](https://www.mentalfloss.com/article/90874/your-pac-man-game-learning-different-strategies-each-ghost)
