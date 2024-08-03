<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <div class="header-container">
        <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/covers/cover-so_long-bonus.png" width="400" alt="Imagem 1"/>
        <img src="https://raw.githubusercontent.com/Matesant/So_long/master/assets/chaves.png" width="200" alt="Imagem 2"/>
    </div>
</body>
</html>

<div style="text-align: center;">
    <h1>✅ So_long</h1>
    <blockquote style="display: inline-block; text-align: center;">
                                       The First Graphical Project of the 42 Curriculum
    </blockquote>
    <pre style="display: inline-block; text-align: center;">

In this project, we are challenged to create a 2D game using the MinilibX library provided by 42.
MinilibX is a lightweight library designed to simplify the creation of basic graphical interfaces and event handling. 
This project is a great opportunity to learn about graphical programming and game logic.
    </pre>
</div>

<h2 align="center" id="how-does-it-work"> How to run </h2>

To play, first compile the project with make:

	make
	
In case you wanna play the bonus version:

	make bonus
	
So, run ./so_long followed by the map:
	
	./so_long map_eazy.ber	

For bonus:
	
	./so_long_bonus map_eazy.ber
	
<h3 id="maps" align="center"> Maps </h3>   

You can parse any kind of map, as long as it respects the below rules:

The map must be a .ber file.

And can only contain these characters:
    
| CHAR |	OBJECT   |
| --------- | ---------- |
| 1         |   Wall   |
| C	        | Coin |
| E	        |   Exit  |
| P         |   Player  |      
| 0         |   Floor     |
    
For bonus there's an extra character - which makes you lose once touch it.
    
| CHAR |	OBJECT   |
| --------- | ---------- |
| K         |   Venom bottle  |


The map must be rectangular and surrounded by walls '1'.

The map must contain at least one exit, one collectible, and one starting position.

in the bonus you can have static enemies
