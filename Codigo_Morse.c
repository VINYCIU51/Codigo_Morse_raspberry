#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <string.h>

#define BOTAO_A 5
#define BOTAO_B 6
#define MAX_SEQ 5
#define TIMEOUT 1500

const char *morse_alfabeto[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
};

const char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *morse_espaco = "-----";

char codigo[MAX_SEQ + 1];
int indice = 0;
absolute_time_t ultima_entrada;

void adicionar_simbolo(char simbolo)
{
    if (indice < MAX_SEQ)
    {
        codigo[indice] = simbolo;
        indice++;
        codigo[indice] = '\0';

        if (indice == 1)
        {
            ultima_entrada = get_absolute_time();
        }
    }
}

char traduzir_morse()
{
    for (int i = 0; i < 26; i++)
    {
        if (strcmp(codigo, morse_espaco) == 0)
        {
            return ' ';
        }

        if (strcmp(codigo, morse_alfabeto[i]) == 0)
        {
            return alfabeto[i];
        }
    }
    return '?';
}

int main()
{
    stdio_init_all();
    gpio_init(BOTAO_A);
    gpio_init(BOTAO_B);
    gpio_set_dir(BOTAO_A, GPIO_IN);
    gpio_set_dir(BOTAO_B, GPIO_IN);
    gpio_pull_up(BOTAO_A);
    gpio_pull_up(BOTAO_B);

    while (1)
    {
        if (gpio_get(BOTAO_A) == 0)
        {
            adicionar_simbolo('.');
            sleep_ms(200);
        }
        if (gpio_get(BOTAO_B) == 0)
        {
            adicionar_simbolo('-');
            sleep_ms(200);
        }
        if (indice > 0)
        {
            int tempo_decorrido = absolute_time_diff_us(ultima_entrada, get_absolute_time()) / 1000;

            if (tempo_decorrido > TIMEOUT)
            {
                char letra = traduzir_morse();
                printf("%c", letra);

                indice = 0;
                memset(codigo, 0, sizeof(codigo));
            }
        }
        sleep_ms(100);
    }
    return 0;
}