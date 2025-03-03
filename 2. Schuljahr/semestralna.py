import numpy as np
import cv2 as cv
import matplotlib.pyplot as plt

# Načítanie obrázka
img = cv.imread('a.jpg', 1)

# Konverzia obrázka na odtiene šedej
gray_img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# Binárna maska pre biele pixely
white_mask = cv.inRange(gray_img, 200, 255)

# Extrahovanie bielych pixelov
white_pixels = cv.bitwise_and(img, img, mask=white_mask)

# Spočítanie priemerného RGB hodnoty pre bielu farbu
average_white_color = np.mean(white_pixels, axis=(0, 1))

print("Priemerná farba bielych pixlov:", average_white_color)

# Zobrazenie výsledkov
plt.subplot(1, 2, 1)
plt.imshow(cv.cvtColor(img, cv.COLOR_BGR2RGB))
plt.title('Pôvodný obrázok')

plt.subplot(1, 2, 2)
plt.imshow(cv.cvtColor(white_pixels, cv.COLOR_BGR2RGB))
plt.title('Biela farba')

plt.show()
