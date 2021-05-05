from pytube import YouTube
from moviepy.editor import *
link=input('Paste the link here:   ')

YouTube(link).streams.first().download()
print('Succesful')
