import filecmp
import os
from pathlib import Path

files = Path("a") #carpeta con los archivos a eliminar
game = Path("b") #carpeta del juego donde se eliminaran los mods

mods_list = []
game_list = []

#Creamos una lista con todos los archivos y carpetas de la carpeta con los mods originales
files = Path(files).glob('*')
for i in files:
    mods_list.append(i)

#Hacemos lo mismo para la carpeta del juego
files = Path(game).glob('*')
for i in files:
    game_list.append(i)

#Comparamos cada archivo y si coinciden se borra el de la carpeta del juego
for mod in mods_list:
    for game in game_list:
        res = filecmp.cmp(mod, game)
        os.remove(game)