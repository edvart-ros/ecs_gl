from PIL import Image
import numpy as np
def reshape_image(image_path, target_width=100, target_height=25):
    img = Image.open(image_path)
    img_array = np.array(img)
    orig_height, orig_width = img_array.shape[:2]
    tile_height = orig_height // 10
    num_tiles = orig_height // tile_height
    reshaped = img_array.reshape(num_tiles, tile_height, orig_width, -1)
    transposed = np.transpose(reshaped, (1, 0, 2, 3))
    final = transposed.reshape(target_height, target_width, -1)
    result = Image.fromarray(final)
    
    return result

result_image = reshape_image('grid.png')
result_image.save('gridN.png')