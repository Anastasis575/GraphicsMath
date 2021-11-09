FROM gcc:latest

RUN mkdir /Build

WORKDIR /GraphicsMath/Build

COPY *.cpp .

COPY *.h .

RUN g++ -o Build.exe main.cpp

CMD ["./Build.exe"]

