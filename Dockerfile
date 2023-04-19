FROM gcc:latest

WORKDIR /app
COPY . .
RUN make clean
CMD ["make"]
