from tkinter import *
import os

root = Tk()
root.title("메모장")
root.geometry("640x480")

scrollbar = Scrollbar(root)
scrollbar.pack(side="right", fill="y")

filename = "mynote.txt"

menu = Menu(root)
def open_file():
  if os.path.isfile(filename):
    with open(filename, "r", encoding="utf8") as file:
      txt.delete("1.0", END)
      txt.insert(END, file.read())
def save_file():
  with open(filename, "w", encoding="utf8") as file:
    file.write(txt.get("1.0", END))
menu_file = Menu(menu, tearoff=0)
menu_file.add_command(label="열기", command=open_file)
menu_file.add_command(label="저장", command=save_file)
menu_file.add_separator()
menu_file.add_command(label="끝내기", command=root.quit)
menu.add_cascade(label="파일", menu=menu_file)
menu.add_cascade(label="편집")
menu.add_cascade(label="서식")
menu.add_cascade(label="보기")
menu.add_cascade(label="도움말")

txt = Text(root, yscrollcommand=scrollbar.set)
txt.pack(side="left", fill="both", expand=True)

scrollbar.config(command=txt.yview)
root.config(menu=menu)
root.resizable(True, False)
root.mainloop()