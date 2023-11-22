import pokepy

client = pokepy.V2Client()

bulbasaur = client.get_pokemon("bulbasaur")

# NAME   
print(bulbasaur.get_types[0].type.name)
