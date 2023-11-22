import pygame
import random

# PYGAME AND VARS
pygame.init()
pygame.mixer.init
width = 1280
height = 720
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Pong")
pygame.RESIZABLE
clock = pygame.time.Clock()
running = True
dt = 0
start = True
score_player1 = 0
score_player2 = 0

#SPEED VALUES SETUP
maxSpeed = 300
midSpeed = 290
minSpeed = 280


#SCORE AND SOUND SETUP
font = pygame.font.Font('C:\\Users\\Marcos\\Documents\\Python Projects\\Pong\\Minecraft.ttf', 32)
hit_sound = pygame.mixer.Sound('C:\\Users\\Marcos\\Documents\\Python Projects\\Pong\Hit.wav')
score_sound = pygame.mixer.Sound('C:\\Users\\Marcos\\Documents\\Python Projects\\Pong\PointScored.wav')

#SPRITES
player = pygame.image.load('C:\\Users\\Marcos\\Documents\\Python Projects\\Pong\\player.png')
ball = pygame.image.load('C:\\Users\\Marcos\\Documents\\Python Projects\\Pong\\Bola.png').convert()

#STARTING POSITIONS
player1_pos = pygame.Vector2(screen.get_width() / 10 , screen.get_height() / 2 - 36)
player2_pos = pygame.Vector2(screen.get_width() * 9 / 10 , screen.get_height() / 2 - 36)
ball_pos = pygame.Vector2(screen.get_width() / 2, screen.get_height() / 2)

#MAIN LOOP
while running:
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # fill the screen with a color to wipe away anything from last frame
    screen.fill("black")

    # RENDER YOUR GAME HERE
    #Draw players and ball
    screen.blit(player, player1_pos)
    screen.blit(player, player2_pos)
    screen.blit(ball, ball_pos)

    #Ball movement
    if start == True:
        velocity_x = random.choice([maxSpeed, midSpeed, minSpeed, -minSpeed, -midSpeed, -maxSpeed])
        velocity_y = random.choice([maxSpeed, midSpeed, minSpeed, -minSpeed, -midSpeed, -maxSpeed])
        start = False
    
    #Ball boundaries and collision
    #Y axis
    if ball_pos.y >= height - 32:
        ball_pos.y = height - 32
        if velocity_y < 0:
            velocity_y = random.choice([maxSpeed, midSpeed, minSpeed])
        else:
            velocity_y = random.choice([-minSpeed, -midSpeed, -maxSpeed])
    if ball_pos.y <= 0:
        ball_pos.y = 0
        if velocity_y < 0:
            velocity_y = random.choice([maxSpeed, midSpeed, minSpeed])
        else:
            velocity_y = random.choice([-minSpeed, -midSpeed, -maxSpeed])
    
    #Player collisions
    if (ball_pos.x >= player1_pos.x) and (ball_pos.x <= player1_pos.x + 32) and (ball_pos.y >= player1_pos.y) and (ball_pos.y <= player1_pos.y + 96):
        ball_pos.x = player1_pos.x + 32
        hit_sound.play()
        if velocity_x < 0:
            velocity_x = random.choice([maxSpeed, midSpeed, minSpeed])
        else:
            velocity_x = random.choice([-minSpeed, -midSpeed, -maxSpeed])
    if (ball_pos.x +  32 >= player2_pos.x) and (ball_pos.x + 32 <= player2_pos.x + 32) and (ball_pos.y >= player2_pos.y) and (ball_pos.y <= player2_pos.y + 96):
        ball_pos.x = player2_pos.x - 32
        hit_sound.play()
        if velocity_x < 0:
            velocity_x = random.choice([maxSpeed, midSpeed, minSpeed])
        else:
            velocity_x = random.choice([-minSpeed, -midSpeed, -maxSpeed])

    #Update ball position
    ball_pos.x += velocity_x * dt
    ball_pos.y += velocity_y * dt

    #Check for movement inputs
    keys = pygame.key.get_pressed()
    if keys[pygame.K_w]:
        player1_pos.y -= maxSpeed * dt
    if keys[pygame.K_s]:
        player1_pos.y += maxSpeed * dt
    if keys[pygame.K_UP]:
        player2_pos.y -= maxSpeed * dt
    if keys[pygame.K_DOWN]:
        player2_pos.y += maxSpeed * dt

    #Limit player momevent zone
    #player 1
    if player1_pos.y >= height - 96:
        player1_pos.y = height - 96
    if player1_pos.y <= 0:
        player1_pos.y = 0
    #player 2
    if player2_pos.y >= height - 96:
        player2_pos.y = height - 96
    if player2_pos.y <= 0:
        player2_pos.y = 0
    
    #Score limits
    if ball_pos.x < 0:
        ball_pos = pygame.Vector2(screen.get_width() / 2, screen.get_height() / 2)
        score_player2 += 1
        score_sound.play()
        start = True
    if ball_pos.x > width - 32:
        ball_pos = pygame.Vector2(screen.get_width() / 2, screen.get_height() / 2)
        score_player1 += 1
        score_sound.play()
        start = True
    
    #Score display
    score1 = font.render(str(score_player1), True, (255, 255, 255), None)
    score2 = font.render(str(score_player2), True, (255, 255, 255), None)
    screen.blit(score1, pygame.Vector2(screen.get_width() / 8, screen.get_height() / 8))
    screen.blit(score2, pygame.Vector2(screen.get_width() * 7 / 8, screen.get_height() / 8))

    # flip() the display to put your work on screen
    pygame.display.flip()
    dt = clock.tick(60) / 1000

pygame.quit()