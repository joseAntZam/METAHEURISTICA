#!/bin/bash

#Comprobamos el numero de argumentos##################################################################################################################################

if [ "$#" -ne 2 ] ;then
	echo "Numero de argumenros incorrecto debes meter como primer argumento ( 1 que representa a greedy o 2 que representa a BL) y como segundo argumento la semilla"
	exit 1
fi

#Comprobamos que los argumentos son correctos#########################################################################################################################
algoritmo="$1"
semilla="$2"

if ! [[ "$algoritmo" =~ ^[1-2]$ ]]; then
    echo "Error: El primer argumento debe ser 1 o 2."
    exit 1
fi

if ! [[ "$semilla" =~ ^[0-9]+$ ]]; then
    echo "Error: El segundo argumento debe ser un entero."
    exit 1
fi

#creamos los ejecutable###############################################################################################################################################

nombre_ejecutable="mochilaCuadratica1EX"



#carpeta donde estan los ficheros#####################################################################################################################################

carpeta="data_QKP_2324/data"

#funcion para convertir a numero , lo que imprime el algoritmo########################################################################################################miarar
convertir_a_numero(){
    local cadena="$1"
    local fitness
    local tiempo

    #fitness=$(awk 'NR==1 {printf "%.10f", $1+0}' <<< "$cadena")
    #tiempo=$(awk 'NR==2 {printf "%.10f", $1+0}' <<< "$cadena")

    #fitness=$(echo "$cadena" | awk 'NR==1 {printf "%.10f", $1+0}'| tr ',' '.')
    fitness=$(echo "$cadena" | awk 'NR==1 {printf $1+0}')
    tiempo=$(echo "$cadena" | awk 'NR==2' | sed 's/[^0-9,.]*//g' )

    #fitness=$(echo "$cadena" | awk 'NR==1' | sed 's/[^0-9,.]*//g')
    #tiempo=$(echo "$cadena" | awk 'NR==2' | sed 's/[^0-9,.]*//g')
    
   
    eval "$2=$fitness"
    eval "$3=$tiempo"

}

#según se greedy o busqueda local meteremos los resultados en un fichero diferente###################################################################################
if [ "$algoritmo" -eq 1 ]; then
    nombre_archivo="ejecucion_greedy.txt"
elif [ "$algoritmo" -eq 2 ]; then
    nombre_archivo="ejecucion_BL.txt"
fi

#contadores beneficios##############################################################################################################################################mirar
contador_jeu_100_25=0.0
contador_jeu_100_50=0.0
contador_jeu_100_75=0.0
contador_jeu_100_100=0.0
contador_jeu_200_25=0.0
contador_jeu_200_50=0.0
contador_jeu_200_75=0.0
contador_jeu_200_100=0.0
contador_jeu_300_25=0.0
contador_jeu_300_50=0.0
#contadores tiempo###################################################################################################################################################mirar
contador_tmp_jeu_100_25=0.0
contador_tmp_jeu_100_50=0.0
contador_tmp_jeu_100_75=0.0
contador_tmp_jeu_100_100=0.0
contador_tmp_jeu_200_25=0.0
contador_tmp_jeu_200_50=0.0
contador_tmp_jeu_200_75=0.0
contador_tmp_jeu_200_100=0.0
contador_tmp_jeu_300_25=0.0
contador_tmp_jeu_300_50=0.0

echo "Ejecutando con semilla $semilla" >> "$nombre_archivo"

#recorremos todos los archivos en la carpeta para buscar los que empiecen con jeu#####################################################################################
for archivojeu in "$carpeta"/jeu*; do
    # Verificar si el archivo comienza con "jeu"
    if [[ -f "$archivojeu" ]]; then
    	
        
    	respuesta=$(./"$nombre_ejecutable" "$archivojeu" "$algoritmo" "$semilla")
        convertir_a_numero "$respuesta" fitness_producido tiempo_producido
        
         echo "Archivo: $archivojeu --> Fitness producido: $fitness_producido -- Tiempo producido: $tiempo_producido" >> "$nombre_archivo"
     
    	if [[ "$archivojeu" == "$carpeta"/jeu_100_25* ]]; then
        	contador_jeu_100_25=$(echo "scale=2; $contador_jeu_100_25 + $fitness_producido" | bc)
            contador_tmp_jeu_100_25=$(echo "$contador_tmp_jeu_100_25 + $tiempo_producido" | bc)
        fi
        if [[ "$archivojeu" == "$carpeta"/jeu_100_50* ]]; then
            contador_jeu_100_50=$(echo "scale=2; $contador_jeu_100_50 + $fitness_producido" | bc)
            contador_tmp_jeu_100_50=$(echo "$contador_tmp_jeu_100_50 + $tiempo_producido" | bc)
        fi
        if [[ "$archivojeu" == "$carpeta"/jeu_100_75* ]]; then
            contador_jeu_100_75=$(echo "scale=2; $contador_jeu_100_75 + $fitness_producido" | bc)
            contador_tmp_jeu_100_75=$(echo "$contador_tmp_jeu_100_75 + $tiempo_producido" | bc)
        fi
        if [[ "$archivojeu" == "$carpeta"/jeu_100_100* ]]; then
            contador_jeu_100_100=$(echo "scale=2; $contador_jeu_100_100 + $fitness_producido" | bc)
            contador_tmp_jeu_100_100=$(echo "$contador_tmp_jeu_100_100 + $tiempo_producido" | bc)
        fi
        if [[ "$archivojeu" == "$carpeta"/jeu_200_25* ]]; then
            contador_jeu_200_25=$(echo "scale=2; $contador_jeu_200_25 + $fitness_producido" | bc)
            contador_tmp_jeu_200_25=$(echo "$contador_tmp_jeu_200_25 + $tiempo_producido" | bc)
        fi
        if [[ "$archivojeu" == "$carpeta"/jeu_200_50* ]]; then
            contador_jeu_200_50=$(echo "scale=2; $contador_jeu_200_50 + $fitness_producido" | bc)
            contador_tmp_jeu_200_50=$(echo "$contador_tmp_jeu_200_50 + $tiempo_producido" | bc)
        fi
        if [[ "$archivojeu" == "$carpeta"/jeu_200_75* ]]; then
            contador_jeu_200_75=$(echo "scale=2; $contador_jeu_200_75 + $fitness_producido" | bc)
            contador_tmp_jeu_200_75=$(echo "$contador_tmp_jeu_200_75 + $tiempo_producido" | bc)
        fi
        if [[ "$archivojeu" == "$carpeta"/jeu_200_100* ]]; then
            contador_jeu_200_100=$(echo "scale=2; $contador_jeu_200_100 + $fitness_producido" | bc)
            contador_tmp_jeu_200_100=$(echo "$contador_tmp_jeu_200_100 + $tiempo_producido" | bc)
        fi
        if [[ "$archivojeu" == "$carpeta"/jeu_300_25* ]]; then
            contador_jeu_300_25=$(echo "scale=2; $contador_jeu_300_25 + $fitness_producido" | bc)
            contador_tmp_jeu_300_25=$(echo "$contador_tmp_jeu_300_25 + $tiempo_producido" | bc)
        fi
        if [[ "$archivojeu" == "$carpeta"/jeu_300_50* ]]; then
        	contador_jeu_300_50=$(echo "scale=2; $contador_jeu_300_50 + $fitness_producido" | bc)
        	contador_tmp_jeu_300_50=$(echo "$contador_tmp_jeu_300_50 + $tiempo_producido" | bc)
        fi
        
    fi
    #echo "Archivo: $archivojeu --> Fitness: $fitness_producido -- Tiempo: $tiempo_producido" >> "$nombre_archivo"
done


echo "FITNESS MEDIO DE CADA ARCHIVO" >> "$nombre_archivo"
echo "100_25: $(echo "scale=2; $contador_jeu_100_25 / 10.0" | bc -l)" >> "$nombre_archivo"
echo "100_50: $(echo "scale=2; $contador_jeu_100_50 / 10.0" | bc -l)" >> "$nombre_archivo"
echo "100_75: $(echo "scale=2; $contador_jeu_100_75 / 10.0" | bc -l)" >> "$nombre_archivo"
echo "100_100: $(echo "scale=2; $contador_jeu_100_100 / 9.0" | bc -l)" >> "$nombre_archivo"
echo "200_25: $(echo "scale=2; $contador_jeu_200_25 / 9.0" | bc -l)" >> "$nombre_archivo"
echo "200_50: $(echo "scale=2; $contador_jeu_200_50 / 10.0" | bc -l)" >> "$nombre_archivo"
echo "200_75: $(echo "scale=2; $contador_jeu_200_75 / 10.0" | bc -l)" >> "$nombre_archivo"
echo "200_100: $(echo "scale=2; $contador_jeu_200_100 / 10.0" | bc -l)" >> "$nombre_archivo"
echo "300_25: $(echo "scale=2; $contador_jeu_300_25 / 9.0" | bc -l)" >> "$nombre_archivo"
echo "300_50: $(echo "scale=2; $contador_jeu_300_50 / 10.0" | bc -l)" >> "$nombre_archivo"

echo "TIEMPO MEDIO DE CADA ARCHIVO" >> "$nombre_archivo"
echo "100_25: $(echo "scale=10; $contador_tmp_jeu_100_25 / 10.0" | bc -l)" >> "$nombre_archivo"
echo "100_50: $(echo "scale=10; $contador_tmp_jeu_100_50 / 10.0" | bc -l)" >> "$nombre_archivo"
echo "100_75: $(echo "scale=10; $contador_tmp_jeu_100_75 / 10.0" | bc -l)" >> "$nombre_archivo"
echo "100_100: $(echo "scale=10; $contador_tmp_jeu_100_100 / 9.0" | bc -l)" >> "$nombre_archivo"
echo "200_25: $(echo "scale=10; $contador_tmp_jeu_200_25 / 9.0" | bc -l)" >> "$nombre_archivo"
echo "200_50: $(echo "scale=10; $contador_tmp_jeu_200_50 / 10.0" | bc -l)" >> "$nombre_archivo"
echo "200_75: $(echo "scale=10; $contador_tmp_jeu_200_75 / 10.0" | bc -l)" >> "$nombre_archivo"
echo "200_100: $(echo "scale=10; $contador_tmp_jeu_200_100 / 10.0" | bc -l)" >> "$nombre_archivo"
echo "300_25: $(echo "scale=10; $contador_tmp_jeu_300_25 / 9.0" | bc -l)" >> "$nombre_archivo"
echo "300_50: $(echo "scale=10; $contador_tmp_jeu_300_50 / 10.0" | bc -l)" >> "$nombre_archivo"

