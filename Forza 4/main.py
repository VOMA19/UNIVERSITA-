import tkinter as tk
from tkinter import messagebox

# Costanti
RIGH = 6
COLONNE = 7
DIMENSIONE_CELLA = 100
RAGGIO = 40
COLORE_SFONDO = '#0055AA'  # Blu classico
COLORE_VUOTO = '#FFFFFF' # Bianco per i buchi vuoti
COLORE_GIOCATORE1 = '#FF0000' # Rosso
COLORE_GIOCATORE2 = '#FFFF00' # Giallo

class Forza4App:
    def __init__(self, root):
        self.root = root
        self.root.title("Forza 4")
        
        # Inizializza la matrice di gioco (6 righe x 7 colonne)
        self.board = [[0 for _ in range(COLONNE)] for _ in range(RIGH)]
        self.turno = 1 # 1 = Giocatore 1 (Rosso), 2 = Giocatore 2 (Giallo)
        self.game_over = False

        # Canvas per disegnare il gioco
        self.canvas = tk.Canvas(root, width=COLONNE*DIMENSIONE_CELLA, height=(RIGH+1)*DIMENSIONE_CELLA, bg=COLORE_SFONDO)
        self.canvas.pack()

        # Collega l'evento click del mouse
        self.canvas.bind("<Button-1>", self.gestisci_click)
        
        # Menu
        menu_bar = tk.Menu(root)
        root.config(menu=menu_bar)
        file_menu = tk.Menu(menu_bar, tearoff=0)
        menu_bar.add_cascade(label="Opzioni", menu=file_menu)
        file_menu.add_command(label="Nuova Partita", command=self.reset_game)
        file_menu.add_separator()
        file_menu.add_command(label="Esci", command=root.quit)

        self.disegna_griglia()

    def disegna_griglia(self):
        self.canvas.delete("all")
        # Disegna la parte superiore (spazio vuoto/indicativo)
        self.canvas.create_rectangle(0, 0, COLONNE*DIMENSIONE_CELLA, DIMENSIONE_CELLA, fill='white', outline='white')
        
        # Disegna la griglia di gioco
        for r in range(RIGH):
            for c in range(COLONNE):
                x0 = c * DIMENSIONE_CELLA
                y0 = (r + 1) * DIMENSIONE_CELLA # +1 perché la riga 0 è per l'intestazione
                x1 = x0 + DIMENSIONE_CELLA
                y1 = y0 + DIMENSIONE_CELLA
                
                # Disegna il rettangolo blu (cella)
                self.canvas.create_rectangle(x0, y0, x1, y1, fill=COLORE_SFONDO, outline=COLORE_SFONDO)
                
                # Disegna il cerchio (pedina o buco)
                colore = COLORE_VUOTO
                if self.board[r][c] == 1:
                    colore = COLORE_GIOCATORE1
                elif self.board[r][c] == 2:
                    colore = COLORE_GIOCATORE2
                
                # Centra il cerchio nella cella
                cx = x0 + DIMENSIONE_CELLA / 2
                cy = y0 + DIMENSIONE_CELLA / 2
                self.canvas.create_oval(cx - RAGGIO, cy - RAGGIO, cx + RAGGIO, cy + RAGGIO, fill=colore, outline='black')
        
        # Indicatore turno
        testo_turno = f"Turno: {'ROSSO' if self.turno == 1 else 'GIALLO'}"
        fill_color = COLORE_GIOCATORE1 if self.turno == 1 else '#CCCC00' # Giallo scuro per testo leggibile su bianco
        self.canvas.create_text(COLONNE*DIMENSIONE_CELLA / 2, DIMENSIONE_CELLA / 2, text=testo_turno, font=("Arial", 20, "bold"), fill=fill_color)

    def gestisci_click(self, event):
        if self.game_over:
            return

        # Determina la colonna cliccata
        col = event.x // DIMENSIONE_CELLA
        
        # Se il click è valido (dentro i bordi)
        if 0 <= col < COLONNE:
            if self.mossa_valida(col):
                riga = self.prossima_riga_disponibile(col)
                self.fai_mossa(riga, col)
                
                if self.controlla_vittoria(self.turno):
                    self.disegna_griglia()
                    vincitore = "ROSSO" if self.turno == 1 else "GIALLO"
                    messagebox.showinfo("Vittoria!", f"Il giocatore {vincitore} ha vinto!")
                    self.game_over = True
                else:
                    self.turno = 1 if self.turno == 2 else 2
                    self.disegna_griglia()

    def mossa_valida(self, col):
        return self.board[0][col] == 0

    def prossima_riga_disponibile(self, col):
        for r in range(RIGH - 1, -1, -1):
            if self.board[r][col] == 0:
                return r
        return -1

    def fai_mossa(self, riga, col):
        self.board[riga][col] = self.turno

    def controlla_vittoria(self, pezzo):
        # Controlla orizzontale
        for c in range(COLONNE - 3):
            for r in range(RIGH):
                if self.board[r][c] == pezzo and self.board[r][c+1] == pezzo and self.board[r][c+2] == pezzo and self.board[r][c+3] == pezzo:
                    return True

        # Controlla verticale
        for c in range(COLONNE):
            for r in range(RIGH - 3):
                if self.board[r][c] == pezzo and self.board[r+1][c] == pezzo and self.board[r+2][c] == pezzo and self.board[r+3][c] == pezzo:
                    return True

        # Controlla diagonale positiva
        for c in range(COLONNE - 3):
            for r in range(RIGH - 3):
                if self.board[r][c] == pezzo and self.board[r+1][c+1] == pezzo and self.board[r+2][c+2] == pezzo and self.board[r+3][c+3] == pezzo:
                    return True

        # Controlla diagonale negativa
        for c in range(COLONNE - 3):
            for r in range(3, RIGH):
                if self.board[r][c] == pezzo and self.board[r-1][c+1] == pezzo and self.board[r-2][c+2] == pezzo and self.board[r-3][c+3] == pezzo:
                    return True
        return False

    def reset_game(self):
        self.board = [[0 for _ in range(COLONNE)] for _ in range(RIGH)]
        self.turno = 1
        self.game_over = False
        self.disegna_griglia()

if __name__ == "__main__":
    root = tk.Tk()
    app = Forza4App(root)
    # Centrare la finestra
    root.eval('tk::PlaceWindow . center')
    root.resizable(False, False)
    root.mainloop()
