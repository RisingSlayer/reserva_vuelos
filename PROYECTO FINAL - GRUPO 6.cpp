/*INTEGRANTES GRUPO 6
- OCHOA QUISPE, ARNOLD JHERICO
- FLORES CALLE, LIDER JACOBY
- ZAMUDIO BALABARCA, AMERICO MARCELO
- SUCA MARIÑO, GARI MARIO
- GUTIERREZ MAZZETTI, STEFANO RENATO
- ESPINOZA LUCIANI, ENRIQUE SAMUEL
----------------------------------------------------------------------------------------
PROBLEMATICA:
Un aeropuerto en convenio con una entidad educativa tiene acceso directo a la reserva
de vuelos para sus estudiantes para lo cual se les proporciona una contraseña de acceso;
se solicita su nombre, sexo, edad, dni y codigo de estudiante; en un menu se mostrara
si el estudiante quiere observar sus datos, modificarlos y elegir el destino de vuelo.
Al elegir el destino se mostraran los destinos, aerolineas y categorias disponibles,
se solicitara si el estudiante desea eligir su asiento (con costo adicional) sino este
se genera aleatoriamente, finalmente el estudiente podra observar su boleta de venta.
----------------------------------------------------------------------------------------
void desactivarMaximizar(); funcion que desactiva ancho del ejecutable
void DibujarCuadro(int x1,int y1,int x2,int y2); funcion que dibuja el margen
void DibujarCuadro2(int xs,int ys,int xi,int yi); funcion que dibuja margen reducido
void CentrarTexto(char *texto, int y); funcion que centra texto
char num(int z); funcion que transforma numeros a letras
void titulo(); funcion de presentacion
void gotoxy(int x,int y); funcion que posiciona
void llenar_datos(int verificador,int boletolisto); funcion que pide datos
void menu(int verificador,int boletolisto); funcion que muestra el menu
void visualizar_datos(int verificador,int boletolisto); funcion que muestra datos
void modificar_datos(int &verificador,int boletolisto); funcion que modifica datos
void elegir_destino(int &opcion2); funcion que muestra destinos
void destinos(int opcion2,int &opcion3); funcion que muestra aerolineas
void categorias(int &clase); funcion que muestra categorias
void generar_boleto_aleatorio(int &boletolisto,int verificador,int clase); funcion que genera boleto aleatorio
void generar_boleto_elegido(int &boletolisto,int verificador,int clase); funcion que genera boleto
void mostrar_boleto(int opcion2,int opcion3); funcion que muestra boleto
void mostrar(int opcion2,int opcion3); funcion que genera el archivo
void final(); funcion de despedida
void password(bool &ingresar); funcion que pide contraseña
*/
//LIBRERIAS
#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
//DEFINIENDO PARAMETROS
#define PASSWORD "fisi21"
#define ubic_arch "d:\\Boleto.dat"
using namespace std;
//PROTOTIPOS
void desactivarMaximizar();
void DibujarCuadro(int x1,int y1,int x2,int y2);
void DibujarCuadro2(int xs,int ys,int xi,int yi);
void CentrarTexto(char *texto, int y);
char num(int z);
void titulo();
void titulo2();
void gotoxy(int x,int y);
void llenar_datos(int verificador,int boletolisto, FILE *f);
void menu(int verificador,int boletolisto, FILE *f);
void visualizar_datos(int verificador,int boletolisto, FILE *f);
void modificar_datos(int &verificador,int boletolisto, FILE *f);
void elegir_destino(int &opcion2, FILE *f);
void destinos(int opcion2,int &opcion3, FILE *f);
void categorias(int &clase, FILE *f);
void generar_boleto_aleatorio(int &boletolisto,int verificador,int clase, FILE *f);
void generar_boleto_elegido(int &boletolisto,int verificador,int clase, FILE *f);
void mostrar_boleto(int opcion2,int opcion3, FILE *f);
void final();
void password(bool &ingresar);
//Registro DATOS
struct Datos{
	string nombre;
	char sexo;
	int edad;
	int dni;
	int codigo;
}persona1;
//Registro PRECIOS
struct Precios{
	string destino;
	int a;
	int b;
	int c;
	int d;
	int e;
}pais[9]={{"NOEXISTE",0,0,0,0,0},
{"Alemania",1810,1800,0,0,1800},
{"BRASIL",340,0,360,350,350},
{"DUBAI",0,0,0,1390,1380},
{"ESTADOS UNIDOS",980,970,0,950,0},
{"FRANCIA",1360,0,0,1600,1650},
{"INGLATERRA",0,2350,2380,0,2300},
{"ITALIA",2100,0,2140,2130,0},
{"JAPON",0,0,2600,2630,0}};
//Registro CATEGORIAS
struct Categorias{
	int a1;
	int b1;
	int c1;
	int d1;
}precios_categorias={200,150,100,50};
//Registro VALOR
struct valor{
	int a2;
	int b2;
	int c2;
	int d2;
	int e2;
	int f2;
	string SIONO;
	int total=0;
	char letra;
	int numero;
}opciones;
//Registro CLASES
struct Clases{
	string clase;
}clase[5]={{"NOEXISTE"},{"PRIMERA CLASE"},{"CLASE EJECUTIVA"},{"CLASE PREMIUM"},{"CLASE TURISTA"}};
//Registro AEROLINEAS
struct Aerolinea{
	string aerolineagod;
}aerolinea[6]={{"NOEXISTE"},{"AMERICAN AIRLINES"},{"COPA AIRLINES"},{"LATAM"},{"SPIRIT AIRLINES"},{"VIVA AIR BARRANCO"}};
//FUNCION PRINCIPAL
int main(){
	//VARIABLES
	FILE *f;
	int verificador=1;
	int boletolisto=0;
	int opcion2,opcion3,clase;
	bool ingresar=false;
	//PROCESO
	desactivarMaximizar();
	system("COLOR 03");
	titulo();
	titulo2();
	password(ingresar);
	if(ingresar==true){
		system("cls");
		llenar_datos(verificador,boletolisto, f);
		menu(verificador,boletolisto, f);
	}
	else{
		return 0;
	}
	//mostrar(opcion2, opcion3);
	//FIN PROCESO
	return 0;
}
//--------------------------------------------------------------------------------------------------------------------
//INCIO DE FUNCIONES SECUNDARIAS
void titulo(){
	CentrarTexto("PROYECTO FINAL",15);
	CentrarTexto("Grupo 6",16);
	for(int i=0;i<=120;i++){
		gotoxy(i,12);cout << "\304";
		gotoxy(120-i,19);cout << "\304";
		Sleep(12);
	}
	system("cls");
}
void titulo2(){
	char a = 92;
	system("cls");
	DibujarCuadro2(0,0,118,29);
	gotoxy(15,5);cout<<"                ______ _____   ____  _____  _    _ ______ _____ _______ ____            ";
	gotoxy(15,6);cout<< "          /"<<a<<"   |  ____|  __ "<<a<<" / __ "<<a<<"|  __ "<<a<<"| |  | |  ____|  __ "<<a<<"__   __/ __ "<<a<<"           ";
	gotoxy(15,7);cout<< "         /  "<<a<<"  | |__  | |__) | |  | | |__) | |  | | |__  | |__) | | | | |  | |          ";
	gotoxy(15,8);cout<< "        / /"<<a<<" "<<a<<" |  __| |  _  /| |  | |  ___/| |  | |  __| |  _  /  | | | |  | |          ";
	gotoxy(15,9);cout<< "       / ____ "<<a<<"| |____| | "<<a<<" "<<a<<"| |__| | |    | |__| | |____| | "<<a<<" "<<a<<"  | | | |__| |          ";
	gotoxy(15,10);cout<< "      /_/    "<<a<<"_"<<a<<"______|_|  "<<a<<"_"<<a<<""<<a<<"____/|_|     "<<a<<"____/|______|_|  "<<a<<"_"<<a<<" |_|  "<<a<<"____/           ";
	gotoxy(15,11);cout<< " _____ _   _ _______ ______ _____  _   _          _____ _____ ____  _   _          _  ";
	gotoxy(15,12);cout<< "|_   _| "<<a<<" | |__   __|  ____|  __ "<<a<<"| "<<a<<" | |   /"<<a<<"   / ____|_   _/ __ "<<a<<"| "<<a<<" | |   /"<<a<<"   | |      ";
	gotoxy(15,13);cout<< "  | | |  "<<a<<"| |  | |  | |__  | |__) |  "<<a<<"| |  /  "<<a<<" | |      | || |  | |  "<<a<<"| |  /  "<<a<<"  | |      ";
	gotoxy(15,14);cout<< "  | | | . ` |  | |  |  __| |  _  /| . ` | / /"<<a<<" "<<a<<"| |      | || |  | | . ` | / /"<<a<<" "<<a<<" | |      "<<endl;
	gotoxy(15,15);cout<< " _| |_| |"<<a<<"  |  | |  | |____| | "<<a<<" "<<a<<"| |"<<a<<"  |/ ____ "<<a<<" |____ _| || |__| | |"<<a<<"  |/ ____ "<<a<<"| |____  ";
	gotoxy(15,16);cout<< "|_____|_| "<<a<<"_|  |_|  |______|_|  "<<a<<"_"<<a<<"_| "<<a<<"_/_/    "<<a<<"_"<<a<<"_____|_____"<<a<<"____/|_| "<<a<<"_/_/    "<<a<<"_"<<a<<"______| ";
	gotoxy(15,17);cout<< "                ____          _____  _____            _   _  _____ ____                   ";
	gotoxy(15,18);cout<< "               |  _ "<<a<<"   /"<<a<<"   |  __ "<<a<<"|  __ "<<a<<"     /"<<a<<"   | "<<a<<" | |/ ____/ __ "<<a<<"                  ";
	gotoxy(15,19);cout<< "               | |_) | /  "<<a<<"  | |__) | |__) |   /  "<<a<<"  |  "<<a<<"| | |   | |  | |                 ";
	gotoxy(15,20);cout<< "               |  _ < / /"<<a<<" "<<a<<" |  _  /|  _  /   / /"<<a<<" "<<a<<" | . ` | |   | |  | |                 ";
	gotoxy(15,21);cout<< "               | |_) / ____ "<<a<<"| | "<<a<<" "<<a<<"| | "<<a<<" "<<a<<"  / ____ "<<a<<"| |"<<a<<"  | |___| |__| |                 ";
	gotoxy(15,22);cout<< "               |____/_/    "<<a<<"_"<<a<<"_|  "<<a<<"_"<<a<<"_|  "<<a<<"_"<<a<<"/_/    "<<a<<"_"<<a<<"_| "<<a<<"_|"<<a<<"_____"<<a<<"____/                  ";
	Sleep(2400);
	system("cls");
}
//FUNCIONES PARA INGRESAR DATOS
void llenar_datos(int verificador,int boletolisto, FILE *f){
	DibujarCuadro(0,0,118,29);
	DibujarCuadro(1,1,116,3);
	f = fopen(ubic_arch, "a+");
   	if (f == NULL){
	   cout<<"\n\n\n\rNo se puede abrir el archivo"<<endl;
	   getche();
	   exit(1);
	}
	fread(&persona1, sizeof(persona1), 1, f);
	CentrarTexto("A E R O P U E R T O    I N T E R N A C I O N A L      B A R R A N C O", 2);
	if(verificador==1){
		CentrarTexto("Ingrese sus datos", 7);
		CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",8);
	}
	if(verificador==2){
		CentrarTexto("Modifique sus datos", 7);
		CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",8);
	}
	fflush(stdin);
	gotoxy(35,11);cout<<"Nombre y Apellidos : ";getline(cin,persona1.nombre);
	do{
		gotoxy(35,13);cout<<"Edad : ";cin>>persona1.edad;
	}while(persona1.edad>125||persona1.edad<=0);
	gotoxy(35,15);cout<<"Sexo (M/F) : ";cin>>persona1.sexo;
	gotoxy(35,17);cout<<"DNI : ";cin>>persona1.dni;
	gotoxy(35,19);cout<<"Codigo Estudiantil : ";cin>>persona1.codigo;		
	system("cls");
	CentrarTexto("S U B I E N D O   D A T O S. . .",12);
	for(int i=47;i<=71;i++){
		gotoxy(i,14);printf("%c",177);
	}
	for(int i=47;i<=71;i++){
		gotoxy(i,14);printf("%c",219);
		Sleep(10);	
	}
	fwrite(&persona1, sizeof(persona1), 1, f);
	if(verificador==1){
		CentrarTexto("Presione [ENTER] para iniciar...",16);
	}
	if(verificador==2){
		CentrarTexto("Datos modificados presione [ENTER] para iniciar...", 16);
	}
	fclose(f);
	getche();
	system("cls");
}
void menu(int verificador,int boletolisto, FILE *f){
	int opcion;
	char siono;
	int opcion2;
	int opcion3;
	DibujarCuadro(0,0,118,29);
	DibujarCuadro(1,1,116,3);
	CentrarTexto("A E R O P U E R T O    I N T E R N A C I O N A L      B A R R A N C O", 2);
	CentrarTexto("M E N U    P R I N C I P A L",7);
	CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",8);
	gotoxy(47,11);cout<<"[ 1 ]	Visualizar datos";
	gotoxy(47,13);cout<<"[ 2 ]	Modificar datos";
	if(boletolisto==0){
		gotoxy(47,15);cout<<"[ 3 ]	Elegir destino";
	}
	if(boletolisto==5){
		gotoxy(47,15);cout<<"[ 3 ]	Ver Boleto";
	}
	gotoxy(47,17);cout<<"[ 4 ]	Salir";
	do{
		gotoxy(47,20);cout<<"Ingrese una opcion [ ]\b\b";
		cin>>opcion;
	}while(opcion>4||opcion<=0);
	switch(opcion){
		case 1:
			system("cls");
			visualizar_datos(verificador,boletolisto, f);
			break;
		case 2:
			system("cls");
			modificar_datos(verificador,boletolisto, f);
			break;
		case 3:
			system("cls");
			if(boletolisto==0){
				elegir_destino(opcion2, f);
			}
			if(boletolisto==5){
				mostrar_boleto(opcion2,opcion3, f);
			}
			break;
	}
	if(opcion==4){
		CentrarTexto("Esta seguro de cerrar el programa?(Y/N) [ ]\b\b",28);
		cin>>siono;
		if(siono=='y'||siono=='Y'){
			final();
		}
		else{
			system("cls");
			menu(verificador,boletolisto,f);
		}
	}
}
void visualizar_datos(int verificador,int boletolisto, FILE *f){
	DibujarCuadro(0,0,118,29);
	DibujarCuadro(1,1,116,3);
	CentrarTexto("A E R O P U E R T O    I N T E R N A C I O N A L      B A R R A N C O", 2);
	CentrarTexto("D A T O S     P E R S O N A L E S",7);
	CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",8);
	gotoxy(45,11);cout<<"Nombre : "<<persona1.nombre;
	gotoxy(45,13);cout<<"Edad : "<<persona1.edad<<" a"<<char(164)<<"os ";
	gotoxy(45,15);cout<<"Sexo : ";
	if(persona1.sexo=='M'||persona1.sexo=='m'){
		cout<<"Masculino";
	}
	else if(persona1.sexo=='F'||persona1.sexo=='f'){
		cout<<"Femenino";
	}
	else{
		cout<<"NO PRECISADO";
	}
	gotoxy(45,17);cout<<"DNI : "<<persona1.dni;
	gotoxy(45,19);cout<<"Codigo Estudiantil : "<<persona1.codigo;
	CentrarTexto("Presione [ENTER] para salir...", 26);
	getche();
	system("cls");
	menu(verificador,boletolisto,f);
}
void modificar_datos(int &verificador,int boletolisto, FILE *f){
	system("cls");
	verificador=2;
	f = fopen(ubic_arch, "r+");
	if(f == NULL){
		cout<<"\n\n\n\rNo se puede abrir el archivo"<<endl;
  		getche();
  		exit(1);
	}
	llenar_datos(verificador,boletolisto, f);
	fwrite(&persona1, sizeof(persona1), 1, f);
	system("cls");
	menu(verificador,boletolisto, f);
	fclose(f);
}
void elegir_destino(int &opcion2, FILE *f){
	int opcion3;
	int verificador=1;
	int boletolisto=0;
	system("cls");
	DibujarCuadro(0,0,118,29);
	DibujarCuadro(1,1,116,3);
	CentrarTexto("A E R O P U E R T O    I N T E R N A C I O N A L      B A R R A N C O", 2);
	do{
		CentrarTexto("D E S T I N O S    D I S P O N I B L E S",7);
		CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",8);
		gotoxy(47,10);cout<<"[ 1 ]	ALEMANIA";
		gotoxy(47,12);cout<<"[ 2 ]	BRASIL";
		gotoxy(47,14);cout<<"[ 3 ]	DUBAI";
		gotoxy(47,16);cout<<"[ 4 ]	ESTADOS UNIDOS";
		gotoxy(47,18);cout<<"[ 5 ]	FRANCIA";
		gotoxy(47,20);cout<<"[ 6 ]	INGLATERRA";
		gotoxy(47,22);cout<<"[ 7 ]	ITALIA";
		gotoxy(47,24);cout<<"[ 8 ]	JAPON";
		gotoxy(47,26);cout<<"[ 9 ]	Salir";
		gotoxy(114,28);cout<<"[ ]\b\b";cin>>opcion2;
	}while(opcion2>9||opcion2<1);
	opciones.a2=opcion2;
	system("cls");
	if(opcion2==9){
		menu(verificador,boletolisto, f);
	}
	else{
		system("cls");
		destinos(opcion2,opcion3,f);
	}
}
void destinos(int opcion2,int &opcion3, FILE *f){
	int clase;
	system("cls");
	DibujarCuadro(0,0,118,29);
	DibujarCuadro(1,1,116,3);
	CentrarTexto("A E R O P U E R T O    I N T E R N A C I O N A L      B A R R A N C O", 2);
	CentrarTexto("A E R O L I N E A S    D I S P O N I B L E S",7);
	CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",8);
	if(pais[opcion2].a==0){
		gotoxy(33,10);cout<<"[ 1 ]	AMERICAN AIRLINES\t\t\tNO DISPONIBLE";
	}
	else{
		gotoxy(33,10);cout<<"[ 1 ]	AMERICAN AIRLINES\t\t\t$"<<pais[opcion2].a;
	}
	if(pais[opcion2].b==0){
		gotoxy(33,12);cout<<"[ 2 ]	COPA AIRLINES\t\t\t\tNO DISPONIBLE";
	}
	else{
		gotoxy(33,12);cout<<"[ 2 ]	COPA AIRLINES\t\t\t\t$"<<pais[opcion2].b;
	}
	if(pais[opcion2].c==0){
		gotoxy(33,14);cout<<"[ 3 ]	LATAM\t\t\t\t\tNO DISPONIBLE";
	}
	else{
		gotoxy(33,14);cout<<"[ 3 ]	LATAM\t\t\t\t\t$"<<pais[opcion2].c;
	}
	if(pais[opcion2].d==0){
		gotoxy(33,16);cout<<"[ 4 ]	SPIRIT AIRLINES\t\t\t\tNO DISPONIBLE";
	}
	else{
		gotoxy(33,16);cout<<"[ 4 ]	SPIRIT AIRLINES\t\t\t\t$"<<pais[opcion2].d;
	}
	if(pais[opcion2].e==0){
		gotoxy(33,18);cout<<"[ 5 ]	VIVA AIR BARRANCO\t\t\tNO DISPONIBLE";
	}
	else{
		gotoxy(33,18);cout<<"[ 5 ]	VIVA AIR BARRANCO\t\t\t$"<<pais[opcion2].e;
	}
	gotoxy(33,22);cout<<"[ 6 ]	SALIR";
	gotoxy(114,28);cout<<"[ ]\b\b";cin>>opcion3;
	opciones.b2=opcion3;
	switch(opcion3){
		case 1:
			if(pais[opcion2].a==0){
				destinos(opcion2,opcion3,f);
			}
			else{
				opciones.total=pais[opciones.a2].a;
			categorias(clase, f);
			}
			break;
		case 2:
			if(pais[opcion2].b==0){
				destinos(opcion2,opcion3,f);
			}
			else{
				opciones.total=pais[opciones.a2].b;
			categorias(clase, f);
			}
			break;
		case 3:
			if(pais[opcion2].c==0){
				destinos(opcion2,opcion3,f);
			}
			else{
				opciones.total=pais[opciones.a2].c;
			categorias(clase, f);
			}
			break;
		case 4:
			if(pais[opcion2].d==0){
				destinos(opcion2,opcion3,f);
			}
			else{
				opciones.total=pais[opciones.a2].d;
			categorias(clase, f);
			}
			break;
		case 5:
			if(pais[opcion2].e==0){
				destinos(opcion2,opcion3,f);
			}
			else{
				opciones.total=pais[opciones.a2].e;
			categorias(clase, f);
			}
			break;
		case 6:
			elegir_destino(opcion2,f);
			break;
	}
}
void categorias(int &clase, FILE *f){
	int boletolisto;
	int verificador;
	char siono2;
	int opcion3;
	int opcion2;
	int opcion4;
	system("cls");
	DibujarCuadro(0,0,118,29);
	DibujarCuadro(1,1,116,3);
	CentrarTexto("A E R O P U E R T O    I N T E R N A C I O N A L      B A R R A N C O", 2);
	do{
		CentrarTexto("C A T E G O R I A S    D I S P O N I B L E S",7);
		CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",8);
		gotoxy(33,10);cout<<"[ 1 ]	PRIMERA CLASE\t\t\t\t$"<<precios_categorias.a1;
		gotoxy(33,12);cout<<"[ 2 ]	CLASE EJECUTIVA\t\t\t\t$"<<precios_categorias.b1;
		gotoxy(33,14);cout<<"[ 3 ]	CLASE PREMIUM\t\t\t\t$"<<precios_categorias.c1;
		gotoxy(33,16);cout<<"[ 4 ]	CLASE TURISTA O ECONOMICA\t\t$"<<precios_categorias.d1;
		gotoxy(33,22);cout<<"[ 5 ]	SALIR";
		gotoxy(114,28);cout<<"[ ]\b\b";cin>>opcion4;
	}while(opcion4>5||opcion4<=0);
	opciones.c2=opcion4;
	switch(opcion4){
		case 1:
			clase=1;
			opciones.total=opciones.total+precios_categorias.a1;
			break;
		case 2:
			clase=2;
			opciones.total=opciones.total+precios_categorias.b1;
			break;
		case 3:
			clase=3;
			opciones.total=opciones.total+precios_categorias.c1;
			break;
		case 4:
			clase=4;
			opciones.total=opciones.total+precios_categorias.d1;
			break;
	}
	if(opcion4!=5){
		CentrarTexto("Desea escoger el asiento? Se le cobrara $10(Y/N) [ ]\b\b",28);
		cin>>siono2;
		if(siono2=='Y'||siono2=='y'){
			opciones.total=opciones.total+10;
			generar_boleto_elegido(boletolisto,verificador,clase,f);
		}
		else if(siono2=='N'||siono2=='n'){
			generar_boleto_aleatorio(boletolisto,verificador,clase, f);
		}
		else{
			categorias(clase, f);
		}
	}else{
		elegir_destino(opcion2,f);
	}
}
//--------------------------------------------------------------------------------------------------------------------
//FUNCIONES QUE GENERAN BOLETOS
void generar_boleto_aleatorio(int &boletolisto,int verificador,int clase, FILE *f){
	opciones.SIONO="SI";
	int ayuda1;
	int numero;
	char letra;
	char letras[]={'A','C','D','E','G','H','J','L'};
	system("cls");
	f = fopen(ubic_arch, "a+");
   	if (f == NULL){
	   cout<<"\n\n\n\rNo se puede abrir el archivo"<<endl;
	   getche();
	   exit(1);
	}
	fread(&persona1, sizeof(persona1), 1, f);
	DibujarCuadro(0,0,118,29);
	DibujarCuadro(1,1,116,3);
	CentrarTexto("A E R O P U E R T O    I N T E R N A C I O N A L      B A R R A N C O", 2);
	CentrarTexto("G E N E R A R    B O L E T O",7);
	CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",12);
	CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",8);
	srand((unsigned)time(0));
	ayuda1=(rand()%8);
	if(clase==1){
		CentrarTexto("PRIMERA CLASE",10);
		numero=rand()%9;
	}
	if(clase==2){
		CentrarTexto("CLASE EJECUTIVA",10);
		numero=(rand()%5)+10;
	}
	if(clase==3){
		CentrarTexto("CLASE PREMIUM",10);
		numero=(rand()%10)+21;
	}
	if(clase==4){
		CentrarTexto("CLASE TURISTA",10);
		numero=(rand()%26)+33;
	}
	fwrite(&persona1, sizeof(persona1), 1, f);
	CentrarTexto("BOLETO GENERADO : ",17);cout<<letras[ayuda1]<<numero<<endl;
		opciones.letra=letras[ayuda1];
		opciones.numero=numero;
		DibujarCuadro2(45,15,77,19);
	letra=letras[ayuda1];
	boletolisto=5;
	CentrarTexto("Presione [ENTER] para volver...",28);
	getche();	
	fclose(f);
	system("cls");
	menu(verificador,boletolisto,f);
}
void generar_boleto_elegido(int &boletolisto,int verificador,int clase, FILE *f){
	opciones.SIONO="NO";
	char letra;
	int fila,columna;
	char ayuda;
	system("cls");
	f = fopen(ubic_arch, "a+");
   	if (f == NULL){
	   cout<<"\n\n\n\rNo se puede abrir el archivo"<<endl;
	   getche();
	   exit(1);
	}
	fread(&persona1, sizeof(persona1), 1, f);
	DibujarCuadro(0,0,118,29);
	DibujarCuadro(1,1,116,3);
	CentrarTexto("A E R O P U E R T O    I N T E R N A C I O N A L      B A R R A N C O", 2);
	CentrarTexto("G E N E R A R    B O L E T O",7);
	CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",8);
	CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",14);
	if(clase==1){
		CentrarTexto("PRIMERA CLASE",10);
		CentrarTexto("Escoga el asiento del 1A - 9L",12);
		do{
			gotoxy(46,16);cout<<"Fila del asiento (1 - 9): ";cin>>fila;
			if(fila>9||fila<1){
				gotoxy(71,16);cout<<"  ";
				gotoxy(72,16);cout<<"  ";
			}
		}while(fila>9||fila<1);
		do{
			gotoxy(46,18);cout<<"Columna del asiento (1 - 8) : ";cin>>columna;
			if(columna>8||columna<1){
				gotoxy(75,18);cout<<"  ";
				gotoxy(76,18);cout<<"  ";
				CentrarTexto("Columnas disponibles: A   C   D   E   G   H   J   L",28);
				Sleep(1650);
				CentrarTexto("                                                     ",28);
			}	
		}while(columna>8||columna<1);
	}
	if(clase==2){
		CentrarTexto("CLASE EJECUTIVA",10);
		CentrarTexto("Escoga el asiento del 11A - 15L",12);
		do{
			gotoxy(46,16);cout<<"Fila del asiento (11 - 15): ";cin>>fila;
			if(fila>15||fila<11){
				gotoxy(71,16);cout<<"     ";
				gotoxy(72,16);cout<<"     ";
				gotoxy(73,16);cout<<"     ";
			}
		}while(fila>15||fila<11);
		do{
			gotoxy(46,18);cout<<"Columna del asiento (1 - 8) : ";cin>>columna;
			if(columna>8||columna<1){
				gotoxy(75,18);cout<<"     ";
				gotoxy(76,18);cout<<"     ";
				CentrarTexto("Columnas disponibles: A,C,D,E,G,H,J,L",28);
				Sleep(1600);
				CentrarTexto("                                       ",28);
			}	
		}while(columna>8||columna<1);
	}
	if(clase==3){
		CentrarTexto("CLASE PREMIUM",10);
		CentrarTexto("Escoga el asiento del 21A - 31L",12);
		do{
			gotoxy(46,16);cout<<"Fila del asiento (21 - 31): ";cin>>fila;
			if(fila>31||fila<21){
				gotoxy(71,16);cout<<"     ";
				gotoxy(72,16);cout<<"     ";
				gotoxy(73,16);cout<<"     ";
			}
		}while(fila>31||fila<21);
		do{
			gotoxy(46,18);cout<<"Columna del asiento (1 - 8) : ";cin>>columna;
			if(columna>8||columna<1){
				gotoxy(75,18);cout<<"  ";
				gotoxy(76,18);cout<<"  ";
				CentrarTexto("Columnas disponibles: A,C,D,E,G,H,J,L",28);
				Sleep(1600);
				CentrarTexto("                                       ",28);
			}	
		}while(columna>8||columna<1);
	}
	if(clase==4){
		CentrarTexto("CLASE TURISTA",10);
		CentrarTexto("Escoga el asiento del 33A - 59L",12);
		do{
			gotoxy(46,16);cout<<"Fila del asiento (33 - 59): ";cin>>fila;
			opciones.numero=fila;
			if(fila>59||fila<33){
				gotoxy(71,16);cout<<"     ";
				gotoxy(72,16);cout<<"     ";
				gotoxy(73,16);cout<<"     ";
			}
		}while(fila>59||fila<33);
		do{
			gotoxy(46,18);cout<<"Columna del asiento (1 - 8) : ";cin>>columna;
			if(columna>8||columna<1){
				gotoxy(75,18);cout<<"  ";
				gotoxy(76,18);cout<<"  ";
				CentrarTexto("Columnas disponibles: A,C,D,E,G,H,J,L",28);
				Sleep(1600);
				CentrarTexto("                                       ",28);
			}	
		}while(columna>8||columna<1);
	}
	ayuda=num(columna);
	opciones.letra=ayuda;
	opciones.numero=fila;
	fwrite(&persona1, sizeof(persona1), 1, f);
	CentrarTexto("BOLETO GENERADO : ",22);cout<<ayuda<<fila;
	DibujarCuadro2(45,20,77,24);
	CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",26);
	CentrarTexto("Presione [ENTER] para volver...",28);
	getche();
	boletolisto=5;
	system("cls");
	fclose(f);
	menu(verificador,boletolisto,f);
}
void mostrar_boleto(int opcion2,int opcion3, FILE *f){
	int verificador;
	int boletolisto=5;
	system("cls");
	DibujarCuadro(0,0,118,29);
	DibujarCuadro(1,1,116,3);
	CentrarTexto("A E R O P U E R T O    I N T E R N A C I O N A L      B A R R A N C O", 2);
	CentrarTexto("B O L E T O    G E N E R A D O",5);
	DibujarCuadro2(35,4,84,28);
	gotoxy(41,7);cout<<"Nombres : "<<persona1.nombre;
	gotoxy(41,9);cout<<"Edad : "<<persona1.edad<<" a"<<char(164)<<"os ";
	gotoxy(41,11);cout<<"Sexo : ";
	if(persona1.sexo=='M'||persona1.sexo=='m'){
		gotoxy(48,11);cout<<"Masculino    ";
	}
	else if(persona1.sexo=='F'||persona1.sexo=='f'){
		gotoxy(48,11);cout<<"Femenino     ";
	}
	else{
		cout<<"NO PRECISADO";
	}
	gotoxy(41,13);cout<<"DNI : "<<persona1.dni;
	gotoxy(41,15);cout<<"Codigo Estudiantil : "<<persona1.codigo;
	gotoxy(41,17);cout<<"Destino : "<<pais[opciones.a2].destino;
	gotoxy(41,19);cout<<"Aerolinea : "<<aerolinea[opciones.b2].aerolineagod;
	gotoxy(41,21);cout<<"Clase : "<<clase[opciones.c2].clase;
	gotoxy(41,23);cout<<"Asiento Aletario : "<<opciones.SIONO;
	gotoxy(41,25);cout<<"N. Asiento : "<<opciones.letra<<opciones.numero;
	gotoxy(41,27);cout<<"TOTAL : $"<<opciones.total;
	gotoxy(114,28);cout<<"[ ]\b\b";;
	getche();
	system("cls");
	menu(verificador,boletolisto,f);
}
void password(bool &ingresar){
	char password[30];
	int intentos=4;
	int v=0;
	do{
		DibujarCuadro(0,0,118,29);
		DibujarCuadro(1,1,116,3);
		DibujarCuadro2(35,13,84,17);
		CentrarTexto("A E R O P U E R T O    I N T E R N A C I O N A L      B A R R A N C O", 2);
		CentrarTexto("I N G R E S E    L A    C O N T R A S E N A",7);
		CentrarTexto("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304",8);
		gotoxy(48,15);cout<<"Password : ";
		for(int i=0;i<30;i++){
			v=getch();
			if((v>='a')&&(v<='z')||(v>='A')&&(v<='Z')||(v>='0')&&(v<='9')||(v>=' ')){
				password[i]=v;
				cout<<"*";
			}
			if(v=='\r'){
				password[i]='\0';
				break;
			}
		}
		if(strcmp(password,PASSWORD)==0){
			gotoxy(45, 27);cout<<"Contrase"<<char(164)<<"a correcta, Bienvenido";
			Sleep(1100);
			ingresar=true;
			system("cls");
			CentrarTexto("C A R G A N D O . . .",13);
			for(int i=47;i<=71;i++){
				gotoxy(i,15);printf("%c",177);
			}
			for(int i=47;i<=71;i++){
				gotoxy(i,15);printf("%c",219);
				Sleep(35);	
			}
		CentrarTexto("Presione [ENTER] para iniciar...",17);
		getche();
		system("cls");
		}
		else{
			gotoxy(45, 27);cout<<"Contrase"<<char(164)<<"a incorrecta";
			intentos--;
			CentrarTexto("N. intentos restantes : ", 28);cout<<intentos;
			Sleep(1200);
			system("cls");
			}
	}while(ingresar==false&&intentos>0);
}
void final(){
	system("cls");
	char a = 92;
	DibujarCuadro2(0,0,118,29);
	DibujarCuadro(1,1,116,3);
	CentrarTexto("A E R O P U E R T O    I N T E R N A C I O N A L      B A R R A N C O", 2);
	gotoxy(20, 12);cout<< "               _____ _____            _____ _____           _____  ";
	gotoxy(20, 13);cout<< "              / ____|  __ "<<a<<"     /"<<a<<"   / ____|_   _|   /"<<a<<"    / ____| ";
	gotoxy(20, 14);cout<< "             | |  __| |__) |   /  "<<a<<" | |      | |    /  "<<a<<"  | (___   ";
	gotoxy(20, 15);cout<< "             | | |_ |  _  /   / /"<<a<<" "<<a<<"| |      | |   / /"<<a<<" "<<a<<"  "<<a<<"___ "<<a<<"  ";
	gotoxy(20, 16);cout<< "             | |__| | | "<<a<<" "<<a<<"  / ____ "<<a<<" |____ _| |_ / ____ "<<a<<" ____) | ";
	gotoxy(20, 17);cout<< "              "<<a<<"_____|_|  "<<a<<"_"<<a<<"/_/    "<<a<<"_"<<a<<"_____|_____/_/    "<<a<<"_"<<a<<"_____/  ";
	getch();
}
//--------------------------------------------------------------------------------------------------------------------
//FUNCIONES ADICIONALES
void DibujarCuadro(int x1,int y1,int x2,int y2){//MejorarCuadro
    for (int i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "\304"; //linea horizontal superior
		gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
	}
    for (int i=y1;i<y2;i++){
		gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
		gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
	}
    gotoxy(x1,y1); cout<< "\332"; 
    gotoxy(x1,y2); cout<< "\300";
    gotoxy(x2,y1); cout<< "\277";
    gotoxy(x2,y2); cout<< "\331";
}
void DibujarCuadro2(int xs,int ys,int xi,int yi){//MejorarCuadro
    for(int i=xs;i<xi;i++){
		gotoxy(i,ys);printf("%c",205); //linea horizontal superior
		gotoxy(i,yi);printf("%c",205); //linea horizontal inferior
	}
    for(int i=ys;i<yi;i++){
		gotoxy(xs,i);printf("%c",186); //linea vertical izquierda
		gotoxy(xi,i);printf("%c",186); //linea vertical derecha
	}
    gotoxy(xs,ys);printf("%c",201);//izq arrriba
    gotoxy(xi,ys);printf("%c",187);
    gotoxy(xs,yi);printf("%c",200);
    gotoxy(xi,yi);printf("%c",188);//derecha abajo
}
void CentrarTexto(char *texto, int y){
	int longitud=strlen(texto);
	gotoxy(60-(longitud/2),y);printf(texto);
}
char num(int z){
	char num;	
	if(z == 1 ){
		num = 'A';
	}
	if(z == 2 ){
		num = 'C';
	}
	if(z == 3 ){
		num = 'D';
	}
	if(z == 4 ){
		num = 'E';
	}
	if(z == 5 ){
		num = 'G';
	}
	if(z == 6 ){
		num = 'H';
	}
	if(z == 7 ){
		num = 'J';
	}
	if(z == 8 ){
		num = 'L';
	}
	return num;
}
void desactivarMaximizar(){
	HWND consoleWindow; 
	consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE,GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}
void gotoxy(int x,int y){
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}
//--------------------------------------------------------------------------------------------------------------------
