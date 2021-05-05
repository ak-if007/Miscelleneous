import pyautogui
from PIL import Image
from pytesseract import *
pytesseract.tesseract_cmd = r'C:\Users\User\AppData\Local\Programs\Tesseract-OCR\tesseract.exe'

img=Image.open("texttoconvert.jpg")

print(pytesseract.image_to_string(img))