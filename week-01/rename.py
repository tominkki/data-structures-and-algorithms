import os 
from os import path

def main():
  entries = os.listdir()
  print(os.listdir())
  workdir = path.split(os.getcwd())[1]

  for entry in entries:
    name, ext = path.splitext(entry)
    if ext == ".zip":
      os.rename(entry, f"Ratkaisut_kierros_{int(workdir.split('-')[1])}_tehtava_{int(name.split('-')[1])}.zip")


if __name__ == "__main__":
  main()

