# **Pac-Man Game**
This project is a replica of the classic Pac-Man Game, originally developed in 1980. <br>
It has been implemented in C++ using the [raylib](https://www.raylib.com/) graphical library. <br>

## 🕹️ **Usage**
To play this game you can use the `make run` command. <br>
This rule will generate a `pac-man` file, which is the zipped version of the game. <br>
You can launch the executable by running the command `./pac-man` <br>
This project currently supports only **Mac** and **Linux** platforms.

## 🎥 **Demo**

<p align="center">
  <img src="./assets/demo.gif" width="100%">
</p>

## 🧬 **Cloning**

To successfully clone this repository, use this command

```shell
git clone https://github.com/maricard18/pac-man-game.git
```

## About
All the graphical components in this game were created using functions from the raylib library; no images or textures were utilized. <br>
The CPU movement pattern was implemented using a self-made random algorithm system. The primary movement is always upwards unless it encounters a dead end. <br> When passing through an intersection or facing a possible new direction, it has a 60% chance of continuing forward and a 40% chance of turning left or right.

## Contributing

Contributions are welcome! Feel free to submit bug reports, feature requests, or pull requests through GitHub.

---
> Feel free to ask me any questions through Slack (**maricard**). <br>
> GitHub [@maricard18](https://github.com/maricard18) &nbsp;&middot;&nbsp;
> Linkedin [Mario Henriques](https://www.linkedin.com/in/mario18) &nbsp;&middot;&nbsp;
> [42 Porto](https://www.42porto.com/en)
