"""
        Server with python, FastAPI

Please run these commands "pip install fastapi", "pip install "uvicorn[standard]""
Run with this command, "uvicorn {thisFilenameWithoutDotpy}:app --reload".
This works like nodemon! It has auto-reload.

    Link with Korean: "https://fastapi.tiangolo.com/ko/"

"""

from typing import Union
from fastapi import FastAPI

app = FastAPI()

# This returns "{"Hello": "World"}" in web page.
@app.get("/")
def read_root():
    return {"Hello": "World"}

@app.get("/items/{item_id}")
def read_item(item_id: int, q: Union[str, None] = None):
    return {"item_id": item_id, "q": q}