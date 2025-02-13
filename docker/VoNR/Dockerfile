FROM debian:bullseye
WORKDIR /app
COPY . .
RUN apt update && apt install -y some_packages
CMD ["/start-ims.sh"]
