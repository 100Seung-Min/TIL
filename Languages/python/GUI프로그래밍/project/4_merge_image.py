from tkinter import *
import tkinter.ttk as ttk
from tkinter import filedialog
import tkinter.messagebox as msgbox
from PIL import Image
import os

root = Tk()
root.title("Baek GUI")

# 파일 추가
def add_file():
  files = filedialog.askopenfilenames(title="이미지 파일을 선택하세요", \
    filetypes=(("PNG 파일", "*.png"), ("모든 파일", "*.*")), \
      initialdir=r"C:\Users\user\Documents\GitHub\TIL\python\GUI프로그래밍\project")
  for file in files:
    list_file.insert(END, file)

# 선택 삭제
def del_file():
  # print(list_file.curselection())
  for index in reversed(list_file.curselection()):
    list_file.delete(index)

# 저장경로
def browse_dest_path():
  folder_selected = filedialog.askdirectory()
  if folder_selected is None:
    return
  txt_dest_path.delete(0,END)
  txt_dest_path.insert(0, folder_selected)

# 이미지 통합
def merge_image():
  # print(list_file.get(0,END))
  images = [Image.open(x) for x in list_file.get(0,END)]
  # widths = [x.size[0] for x in images]
  # heights = [x.size[1] for x in images]
  widths, heights = zip(*(x.size for x in images))
  max_width, total_height = max(widths), sum(heights)
  result_img = Image.new("RGB", (max_width, total_height), (255,255,255))
  y_offset = 0
  # for img in images:
  #   result_img.paste(img, (0, y_offset))
  #   y_offset += img.size[1]
  for idx, img in enumerate(images):
    result_img.paste(img, (0, y_offset))
    y_offset += img.size[1]
    progress = (idx + 1) / len(images) * 100
    p_var.set(progress)
    progress_bar.update()
  dest_path = os.path.join(txt_dest_path.get(), "Baek_photo.jpg")
  result_img.save(dest_path)
  msgbox.showinfo("알림", "작업이 완료되었습니다")

# 시작
def start():
  print("가로넓이 :", cmb_width.get())
  print("간격 :", cmb_space.get())
  print("포맷 :", cmb_format.get())
  if list_file.size() == 0:
    msgbox.showwarning("경고", "이미지 파일을 추가하세요")
  if len(txt_dest_path.get()) == 0:
    msgbox.showwarning("경고", "저장 경로를 선택하세요")
  merge_image()

# 파일 프레임
file_frame = Frame(root)
file_frame.pack(fill="x", padx=5, pady=5)
btn_add_file = Button(file_frame, text="파일추가", padx=5, pady=5, width=10, command=add_file)
btn_add_file.pack(side="left")
btn_del_file = Button(file_frame, text="선택삭제", padx=5, pady=5, width=10, command=del_file)
btn_del_file.pack(side="right")

# 리스트 프레임
list_frame = Frame(root)
list_frame.pack(fill="both", padx=5, pady=5)
Scrollbar = Scrollbar(list_frame)
Scrollbar.pack(side="right", fill="y")
list_file = Listbox(list_frame, selectmode="extended", height=15, yscrollcommand=Scrollbar.set)
list_file.pack(side="left", fill="both", expand=True)
Scrollbar.config(command=list_file.yview)

# 저장 경로 프레임
path_frame = LabelFrame(root, text="저장경로")
path_frame.pack(fill="x", padx=5, pady=5, ipady=5)
txt_dest_path = Entry(path_frame)
txt_dest_path.pack(side="left", fill="x", expand=True, ipady=4, padx=5, pady=5)
btn_dest_path = Button(path_frame, text="찾아보기", width=10, command=browse_dest_path)
btn_dest_path.pack(side="right", padx=5, pady=5)

# 옵션 프레임
frame_option = LabelFrame(root, text="옵션")
frame_option.pack(padx=5, pady=5, ipady=5)

# 가로 넓이
opt_width = ["원본유지", "1024", "800", "640"]
ldl_width = Label(frame_option, text="가로넓이", width=8)
ldl_width.pack(side="left", padx=5, pady=5)
cmb_width = ttk.Combobox(frame_option, state="readonly", values=opt_width, width=10)
cmb_width.current(0)
cmb_width.pack(side="left", padx=5, pady=5)

# 간격
opt_space = ["없음", "좁게", "보통", "넓게"]
ldl_space = Label(frame_option, text="가로넓이", width=8)
ldl_space.pack(side="left", padx=5, pady=5)
cmb_space = ttk.Combobox(frame_option, state="readonly", values=opt_space, width=10)
cmb_space.current(0)
cmb_space.pack(side="left", padx=5, pady=5)

# 파일 포맷
opt_format = ["PNG", "JPG", "BMP"]
ldl_format = Label(frame_option, text="포맷", width=8)
ldl_format.pack(side="left", padx=5, pady=5)
cmb_format = ttk.Combobox(frame_option, state="readonly", values=opt_format, width=10)
cmb_format.current(0)
cmb_format.pack(side="left", padx=5, pady=5)

# 진행상황
frame_progress = LabelFrame(root, text="진행상황")
frame_progress.pack(fill="x", padx=5, pady=5, ipady=5)
p_var = DoubleVar()
progress_bar = ttk.Progressbar(frame_progress, maximum=100, variable=p_var)
progress_bar.pack(fill="x", padx=5, pady=5)

# 실행 프레임
frame_run = Frame(root)
frame_run.pack(fill="x", padx=5, pady=5)
btn_close = Button(frame_run, text="닫기", padx=5, pady=5, width=12, command=root.quit)
btn_close.pack(side="right", padx=5, pady=5)
btn_start = Button(frame_run, text="시작", padx=5, pady=5, width=12, command=start)
btn_start.pack(side="right", padx=5, pady=5)

root.resizable(False,False)
root.mainloop()