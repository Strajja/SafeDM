FROM gcc:latest

WORKDIR /app

COPY . .

RUN g++ main.cpp -o messenger -pthread

CMD ["./messenger"]