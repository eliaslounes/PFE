Building/Compiling gNB:
apt-get install cmake make gcc g++ pkg-config libfftw3-dev libmbedtls-dev libsctp-dev libyaml-cpp-dev libgtest-dev git curl jq -y
apt-get install libuhd-dev libuhd4.6.0 uhd-host -y
find /  -name "uhd_images_downloader.py"
sudo /usr/libexec/uhd/utils/uhd_images_downloader.py
export UHD_IMAGES_DIR=/usr/share/uhd/images
uhd_find_devices
git clone https://github.com/srsran/srsRAN_Project.git
cd srsRAN_Project/
mkdir build
cd build/
cmake ../ -DENABLE_EXPORT=ON -DUHD=ON
make -j`nproc`
make install
ldconfig
cp /root/srsRAN_Project/build/apps/gnb /usr/bin/gnb

------------------------------------------------------------------------------------------------------------------
fichier de config gnb.yml avec usrp:
------------------------------------------------------------------------------------------------------------------
amf:
  addr: 10.53.1.2                  # The address or hostname of the AMF.
  bind_addr: 10.53.1.1             # A local IP that the gNB binds to for traffic from the AMF.

ru_sdr:
  device_driver: uhd                # The RF driver name.
  device_args: type=b200            # Optionally pass arguments to the selected RF driver.
  clock: external                   # Use external reference clock with USRP B210.
  srate: 23.04                      # RF sample rate might need to be adjusted according to selected bandwidth.
  tx_gain: 75                       # Transmit gain of the RF might need to adjusted to the given situation.
  rx_gain: 75                       # Receive gain of the RF might need to adjusted to the given situation.. 

cell_cfg:
  dl_arfcn: 368500                  # ARFCN of the downlink carrier (center frequency).
  band: 3                           # The NR band.
  channel_bandwidth_MHz: 20         # Bandwith in MHz. Number of PRBs will be automatically derived.
  common_scs: 15                    # Subcarrier spacing in kHz used for data.
  plmn: "00101"                     # PLMN broadcasted by the gNB.
  tac: 7                            # Tracking area code (needs to match the core configuration).
  pdcch:
    common:
      ss0_index: 0                  # Set search space zero index to match srsUE capabilities
      coreset0_index: 12            # Set search CORESET Zero index to match srsUE capabilities
    dedicated:
      ss2_type: common              # Search Space type, has to be set to common
      dci_format_0_1_and_1_1: false # Set correct DCI format (fallback)
  prach:
    prach_config_index: 1           # Sets PRACH config to match what is expected by srsUE

cu_cp:
  inactivity_timer: 7200            # Sets the UE/PDU Session/DRB inactivity timer to 7200 seconds. Supported: [1 - 7200].

log:
  filename: /tmp/gnb.log            # Path of the log file.
  all_level: debug                   # Logging level applied to all layers.
  hex_max_size: 0

pcap:
  mac_enable: true                 # Set to true to enable MAC-layer PCAPs.
  mac_filename: /tmp/gnb_mac.pcap   # Path where the MAC PCAP is stored.
  ngap_enable: true                # Set to true to enable NGAP PCAPs.
  ngap_filename: /tmp/gnb_ngap.pcap # Path where the NGAP PCAP is stored.
  
--------------------------------------------------------------------------------------------------------------------------------------------
Commandes pour l'horloge :
--------------------------------------------------------------------------------------------------------------------------------------------
uhd_usrp_probe | grep "Clock Source"
uhd_usrp_probe --args="clock_source=external"

----------------------------------------------------------------------------------------------------------------------------------------------
Mongo DB:
----------------------------------------------------------------------------------------------------------------------------------------------
docker exec -it open5gs_5gc mongosh --port 27017
use open5gs

=============================================
db.subscribers.insertOne({
  "imsi": "001010000000002",
  "security": {
    "k": "00112233445566778899aabbccddeeff",
    "opc": "63bfa50ee6523365ff14c1f45f88737d"
  },
  "ambr": {
    "uplink": "1Gbps",
    "downlink": "1Gbps"
  },
  "slice": [
    {
      "sst": 1,
      "default_indicator": true,
      "session": [
        {
          "name": "internet",
          "type": 1,
          "pcc_rule": [],
          "ambr": {
            "uplink": "1Gbps",
            "downlink": "1Gbps"
          },
          "qos": {
            "index": 9
          }
        }
      ]
    }
  ]
})

------------------------------------------------------------------------------------------------------------------
pysim:
-----------------------------------------------------------------------------------------------------------------
git clone https://github.com/osmocom/pysim
cd pysim
sudo apt-get install --no-install-recommends \
    pcscd libpcsclite-dev \
    python3 \
    python3-setuptools \
    python3-pyscard \
    python3-pip
pip3 install -r requirements.txt

=====================================================================================================================

pcsc_scan
./pySim-read.py -p 

---------------------------------------------------------------------------------------------------------------------------
smf:
  sessions:
    - apn: srsapn
      type: ipv4
      ue_ip_pool: 10.45.0.0/16
      dns:
        - 8.8.8.8
        - 8.8.4.4

---------------------------------------------------------------------------------------------------------------------------------------

upf:
  gtpu:
    - addr: 192.168.1.10  # Adresse IP de l'interface connectée à Internet
  pfcp:
    - addr: 127.0.0.1
  subnet:
    - addr: 10.45.0.1/16  # Doit correspondre à l'IP pool de smf.yaml
      dnn: srsapn
