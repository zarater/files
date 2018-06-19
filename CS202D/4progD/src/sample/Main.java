package sample;

import java.util.Scanner;

import static java.lang.String.*;

public class Main {
    public static Parades para = new Parades();
    public static Games gamer = new Games();
    public static Music tunes = new Music();
    protected static Scanner input;

    public static void main(String[] args) {
        String response;
        input = new Scanner(System.in);

        System.out.println("Welcome to Lundquist Festive Tracker!");
        System.out.println();
        System.out.println("What activity would you like to track? There is the Parades(P), Fun and Games(G), and Live Music(M)");
        response = input.nextLine();
        response = response.toUpperCase();
        switch (response){
            case "P":
                Cars();

            case "G":
                Fun();

            case "M":
                Live();
        }
    }

    public static void Cars(){
        String response;
        System.out.println("What would you like to do? Display all parades(D), Display all activitise(A), or remove all activities(R)?");
        response = input.nextLine();
        response = response.toUpperCase();
        switch(response){
            case "D":
                para.Display();
                Again();

            case "A":
                para.Display_all();
                Again();

            case "R":
                para.Remove_all();
                System.out.println("All activities removed.");
                Again();
        }
    }

    public static void Fun(){
        String response;
        System.out.println("What would you like to do? Display all games(D), Display all activities(A), or remove all activities(R)?");
        response = input.nextLine();
        response = response.toUpperCase();
        switch(response) {
            case "D":
                gamer.Display();
                Again();

            case "A":
                gamer.Display_all();
                Again();

            case "R":
                gamer.Remove_all();
                System.out.println("All activities removed.");
                Again();
        }
    }
        public static void Live(){
            String response;
            System.out.println("What would you like to do? Display all live music(D), Display all activities(A), or remove all activities(R)?");
            response = input.nextLine();
            response = response.toUpperCase();
            switch(response) {
                case "D":
                    tunes.Display();
                    Again();

                case "A":
                    tunes.Display_all();
                    Again();

                case "R":
                    tunes.Remove_all();
                    System.out.println("All activities removed.");
                    Again();
            }
    }

    public static void Again(){
        String response;
        System.out.println("Would you like to continue?");
        response = input.nextLine();
        response.toUpperCase();
        switch (response){
            case "Y":
                new Main();

            case "N":
                break;
        }
    }
}
