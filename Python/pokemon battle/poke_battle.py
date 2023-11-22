"""
========================================
                TO DO
========================================

    - Moves:
        - Better damage formula
        - STAB
        - LEVEL and stat scaling
    - UI (Pygame)
========================================
"""

import random
import pandas as pd

# TYPE CHART SETUP
TypeChartxlsx = pd.read_excel("Python\pokemon battle/Type_Chart.xlsx")
#print(TypeChartxlsx)
TypeChart = TypeChartxlsx.to_dict()

# POKEMON TYPES AND STATS XLSX SETUP
Pokemon_mainxlsx = pd.read_excel("Python\pokemon battle\Pokemon_main.xlsx")
Pokemon_main = Pokemon_mainxlsx.to_dict()

class Pokemon:
    def __init__(self, name, type0, type1, health, attack, defense, speed):
        self.name = name
        self.type0 = type0
        self.type1 = type1
        self.health = health
        self.attack = attack
        self.defense = defense
        self.speed = speed


# POKEMON SETUP
in_ally = input("Input the name of your pokemon: ")
in_enemy = input("Input the name of the enemy pokemon: ")

index = list(list(Pokemon_main.values())[0].values()).index(in_ally)
name = str(list(list(Pokemon_main.values())[0].values())[index])
type0 = str(list(list(Pokemon_main.values())[1].values())[index])
type1 = str(list(list(Pokemon_main.values())[2].values())[index])
hp = str(list(list(Pokemon_main.values())[3].values())[index])
atk = str(list(list(Pokemon_main.values())[4].values())[index])
defs = str(list(list(Pokemon_main.values())[5].values())[index])
spe = str(list(list(Pokemon_main.values())[6].values())[index])
player_pok = Pokemon(name, type0, type1, int(hp), int(atk), int(defs), int(spe)) 
# print(f'player_pok: {player_pok.name} TYPE0: {player_pok.type0} TYPE1: {player_pok.type1} HP:{player_pok.health} ATK:{player_pok.attack} DEF:{player_pok.defense} SPE: {player_pok.speed}')

index = list(list(Pokemon_main.values())[0].values()).index(in_enemy)
name = str(list(list(Pokemon_main.values())[0].values())[index])
type0 = str(list(list(Pokemon_main.values())[1].values())[index])
type1 = str(list(list(Pokemon_main.values())[2].values())[index])
hp = str(list(list(Pokemon_main.values())[3].values())[index])
atk = str(list(list(Pokemon_main.values())[4].values())[index])
defs = str(list(list(Pokemon_main.values())[5].values())[index])
spe = str(list(list(Pokemon_main.values())[6].values())[index])
enemy_pok = Pokemon(name, type0, type1, int(hp), int(atk), int(defs), int(spe))
# print(f'enemy_pok: {enemy_pok.name} TYPE0: {enemy_pok.type0} TYPE1: {enemy_pok.type1} HP:{enemy_pok.health} ATK:{enemy_pok.attack} DEF:{enemy_pok.defense} SPE: {enemy_pok.speed}')


def battle(ally, enemy):
    def speed_check():
        global first_attacker
        global second_attacker
        if ally.speed > enemy.speed:
            first_attacker = ally 
            second_attacker = enemy
        else:
            first_attacker = enemy
            second_attacker = ally
        return first_attacker, second_attacker
    first_attacker = speed_check()[0]
    second_attacker = speed_check()[1]
    # print(f'first attacker: {first_attacker.name} TYPE0: {first_attacker.type0} TYPE1: {first_attacker.type1} HP:{first_attacker.health} ATK:{first_attacker.attack} DEF:{first_attacker.defense}')
    # print(f'second attacker: {second_attacker.name} TYPE0: {second_attacker.type0} TYPE1: {second_attacker.type1} HP:{second_attacker.health} ATK:{second_attacker.attack} DEF:{second_attacker.defense}')
    
    def type_matchup():
        # FIRST TYPE CHECK
        index = list(list(TypeChart.values())[0].values()).index(second_attacker.type0)
        # SEARCH FOR WEAKNESS 
        w_0 = list(list(TypeChart.values())[1].values())[index]
        # SEARCH FOR RESISTANCE 
        r_0 = list(list(TypeChart.values())[2].values())[index]
        # SEARCH FOR IMMUNITIES
        if isinstance(list(list(TypeChart.values())[3].values())[index], str):
            i_0 = list(list(TypeChart.values())[3].values())[index]
            immunities_0 = i_0.split(", ")
        else: immunities_0 = []

        # SECOND TYPE CHECK
        if second_attacker.type1 != 'nan':
            index = list(list(TypeChart.values())[0].values()).index(second_attacker.type1)
            # SEARCH FOR WEAKNESS 
            w_1 = list(list(TypeChart.values())[1].values())[index]
            # SEARCH FOR RESISTANCE 
            r_1 = list(list(TypeChart.values())[2].values())[index]
            # SEARCH FOR IMMUNITIES
            if isinstance(list(list(TypeChart.values())[3].values())[index], str):
                i_1 = list(list(TypeChart.values())[3].values())[index]
                immunities_1 = i_1.split(", ")
            else: immunities_1 = []

            weakness_1 = w_1.split(", ")
            resistance_1 = r_1.split(", ")   
        else:
            w_1 = []
            r_1 = []
            weakness_1 = []
            resistance_1 = []
            immunities_1 = []
        
        weakness_0 = w_0.split(", ")
        double_weakness = []
        resistance_0 = r_0.split(", ")
        double_resistance = []

        # DOUBLE EFFECT CHECK 
        weakness_total = weakness_0 + weakness_1
        resistance_total = resistance_0 + resistance_1
        immunities_total = immunities_0 + immunities_1
        nt = []
        for i in weakness_total:
            if i in nt: double_weakness.append(i)
            else: nt.append(i)

        weakness_total = nt
        nt = []

        for i in resistance_total:
            if i in nt: double_resistance.append(i)
            else:nt.append(i)
        resistance_total = nt

        # COUNTEREFFECT CHECK
        nt = [] #return 1 (NEUTRAL)
        for i in weakness_total:
            if i in resistance_total: 
                nt.append(i)
                weakness_total.remove(i)
                resistance_total.remove(i)
            elif i in immunities_total: weakness_total.remove(i)
        for i in resistance_total: 
            if i in immunities_total: resistance_total.remove(i)

        # DEBUG
        # print(f'x4: {double_weakness}')
        # print(f'x2: {weakness_total}')
        # print(f'x1: {nt}')
        # print(f'x0.5: {resistance_total}')
        # print(f'x0.25: {double_resistance}')

        # RETURN VALUE
        if first_attacker.type0 in double_weakness: return 4
        elif first_attacker.type0 in weakness_total: return 2
        elif first_attacker.type0 in resistance_total: return 0.5
        elif first_attacker.type0 in double_resistance: return 0.25
        elif first_attacker.type0 in immunities_total: return 0
        else: return 1

    def dmg_calc():
        if random.randrange(1, 16) == 1: crit = 1.5 
        else: crit = 1
        damage = round(((first_attacker.attack*random.uniform(0.85,1.15))-((second_attacker.defense/2)*random.uniform(0.85,1.15)))*type_matchup()*crit)
        return damage
    
    def take_dmg(damage):
        damage = dmg_calc()
        # print(f'damage dealt: {damage}')
        second_attacker.health = second_attacker.health - damage
        if second_attacker.health < 0: second_attacker.health = 0
        print(f'{first_attacker.name} has dealt {damage} HP!')
        print(f"{second_attacker.name}'s health is now {second_attacker.health}")
    
    speed_check()
    take_dmg(dmg_calc())

    #DEBUG
    # print(f'type effectiveness: {type_matchup()}')
    # print(f'health: {second_attacker.health}')
    # print(f'dmg_multiplier = {type_matchup()}')

battle(player_pok, enemy_pok)