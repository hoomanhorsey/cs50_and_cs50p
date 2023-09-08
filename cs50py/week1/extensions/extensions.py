

# obtains filename from user, strips whitespace, makes lowercase
filename = input("File name: ").strip().lower()

# excludes filenames without extensions
if "." not in filename:
    print("application/octet-stream")

# for filenames with extensions "."
else:

    ext = filename.split(".")   # splits filename up by '.', and creates a list
    length = len(ext)           # finds number of items in list

    match ext[length - 1]:      # matches last item in list, which will be an extension, if any

        case "gif":
            print("image/gif ")
        case "jpeg" | "jpg":
            print("image/jpeg ")
        case "png":
            print("image/png")
        case "pdf":
            print("application/pdf ")
        case "txt":
            print("text/plain")
        case "zip":
            print("application/zip")
        case _:
            print("application/octet-stream")
