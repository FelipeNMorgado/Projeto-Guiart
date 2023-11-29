import pygame
import os
import serial

def reproduzir_musica(caminho_musica):
    pygame.mixer.init()
    pygame.mixer.music.load(caminho_musica)
    pygame.mixer.music.play()

    while pygame.mixer.music.get_busy():
        if ser.in_waiting > 0:
            escolha = ser.read().decode('utf-8').strip()  # Remova espaços em branco adicionais
            print("Comando recebido:", escolha)
            if escolha == '1':
                print("Reproduzindo Música 1")
                pygame.mixer.music.stop()  # Pare a música atual antes de iniciar uma nova
                reproduzir_musica(musica1_path)
            elif escolha == '2':
                print("Reproduzindo Música 2")
                pygame.mixer.music.stop()  # Pare a música atual antes de iniciar uma nova
                reproduzir_musica(musica2_path)
            elif escolha.lower() == '3':
                print("Parando a música")
                pygame.mixer.music.stop()
            else:
                print("Comando inválido.")

print("Olá")

musica1_path = 'IMG_6764.mp3'
musica2_path = 'abaporu descrição .mp3'

if os.path.exists(musica1_path) and os.path.exists(musica2_path):
    ser = serial.Serial('COM8', 9600)

    print("Aguardando comandos do Arduino...")

    while True:
        if ser.in_waiting > 0:
            escolha = ser.read().decode('utf-8').strip()
            print(f"Comando recebido: {escolha}")
            if escolha == '1':
                print("Reproduzindo Música 1")
                reproduzir_musica(musica1_path)
            elif escolha == '2':
                print("Reproduzindo Música 2")
                reproduzir_musica(musica2_path)

            elif escolha.lower() == '3':
                print("Parando a música")
                pygame.mixer.music.stop()
            
            else:
                print("Comando inválido.")

